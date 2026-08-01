#pragma once
#include <iostream>
#include "Sample.h"
#include "GenRandom.h"
#include "Utils.h"

namespace PerceptronModel {

	//returns the error of the classification during training in order to tune the weights accordingly
	double getError (double target, double y) {
		return target - y;
	}
	
	class Perceptron {
		private:
			//the errors count is mandatory for the model to know when to stop training
			int epochs, epochs_threshold, errors_count;
			
			std::vector<double> weights;
			double bias;
			
			double learning_step; //learning step
			int dimensions; //dimensions

		public:
			//constructor gets the features dimension as a parameter	
			Perceptron(int dim): dimensions{dim}, epochs{0}, epochs_threshold{5000}, errors_count{0} {
				GenRandomReal gen_step{0.06, 0.1}, gen_bias{-0.5, 0.5 }, gen_weight{-0.5, 0.5};

				//generate random starting learning step
				this->learning_step = gen_step();

				//generate random starting bias
				this->bias = gen_bias();
				
				//initialize weights
				for (int i=0; i<dim; i++) {
					weights.push_back(gen_weight());
				}
			};

			int stepFunction(const std::vector<double> &sample, const std::vector<double> weights) {
				double dp = Utils::dotProduct(weights, sample) + this->bias;
				return dp > 0 ? 1 : 0;
			}
	
			void recalculateWeights (double error, std::vector<double> features ) {
				for (int i=0; i<weights.size(); i++) {
					weights[i] = weights[i] + learning_step*error*features[i];
				}
				bias = bias + learning_step * error;
			}
				
			/*
				The training dataset consists of pairs, in which the first element is the sample features (vector) 
				and the second element is the correct target (label)
			*/
			void train (std::vector<std::pair<std::vector<double>, int>> training_set ) {
				do {
					this->errors_count = 0;

					for (auto &sample: training_set) {
						std::vector<double> features = sample.first; 
						int target = sample.second;
						int y = stepFunction(features, this->weights);

						double error = getError(target, y);	
						if (error != 0) {
							this->errors_count += 1;
							recalculateWeights(error, features);
						}
					}

					this->epochs += 1;
				}
				while (this->errors_count > 0 && epochs < epochs_threshold);
			}
				
			int predict (std::vector<double> validation_sample) {
				return stepFunction(validation_sample, weights);
			}

			std::vector<double> getWeights () const {
				return weights;
			}

			double getLearningStep () const {
				return learning_step;
			}

			std::pair<int, int> getTrainingMetrics () const {
				return std::make_pair(this->errors_count, this->epochs);
			}

			int getEpochsThreshold () const {
				return this->epochs_threshold;
			}
	};

	std::ostream &operator<<(std::ostream &stream,  const Perceptron &p) {
		//displaying model's parameters, hyperparameters and settings
		
		std::cout << "===============" << std::endl;
		std::cout << "Weights: "; 
		for (auto &x: p.getWeights()) {
			std::cout << x << ", ";
		}
		std::cout << std::endl;
		std::cout << "===============" << std::endl;
		
		std::cout << "Learning rate: " << p.getLearningStep();
		
		std::cout << std::endl;
		std::cout << "===============" << std::endl;

		auto metrics = p.getTrainingMetrics();
		std::cout << "Errors: " << metrics.first << ", Epochs: " << metrics.second << ", Epochs Threshold: " << p.getEpochsThreshold() << std::endl;
		std::cout << "===============";

		return stream;
	}

}
