#pragma once
#include <iostream>
#include "GenRandom.h"
#include "Utils.h"
#include <string>
#include <fstream>

namespace PerceptronModel {

	//returns the error of the classification during training in order to tune the weights accordingly
	double getError (double target, double y) {
		return target - y;
	}
	
	class Perceptron {
		private:
			// the errors count is mandatory for the model to know when to stop training
			// when the errors count reaches zero then the model is ready to make predictions
			// it means that the dataset was logicaly separated by the weigthed sum

			int epochs;
			int epochs_threshold;
			int errors_count;
			
			std::vector<double> weights;
			double bias;
			
			double learning_step; //learning step
			int dimensions; //dimensions

		public:
			//constructor gets the features dimension as a parameter	
			Perceptron(int dim): dimensions{dim}, learning_step{0.1}, epochs{0}, epochs_threshold{2000}, errors_count{0} {

				GenRandomReal gen_bias{ -0.5, 0.5 }, gen_weight{ -0.5, 0.5 };

				//generate random starting bias
				this->bias = gen_bias();
				
				//initialize weights
				for (int i=0; i<dim; i++) {
					weights.push_back(gen_weight());
				}
			};

			int stepFunction(const std::vector<double> &sample) const {
				double dp = Utils::dotProduct(weights, sample) + this->bias;
				return dp > 0 ? 1: 0;
			}
	
			void recalculateWeights (const double &error, const std::vector<double> &features ) {
				for (int i=0; i<weights.size(); i++) {
					weights[i] = weights[i] + learning_step*error*features[i];
				}
				bias = bias + learning_step * error;
			}
				
			/*
				The training dataset consists of pairs, in which the first element is the sample features (vector) 
				and the second element is the correct target (label)
				0: male
				1: female
			*/
			
			void train (const std::vector<std::pair<std::vector<double>, int>> &training_set ) {
				do {
					this->errors_count = 0;
					
					for (auto &sample: training_set) {
						std::vector<double> features = sample.first; 
						int target = sample.second;
						int y = stepFunction(features);
						
						double error = getError(target, y);	
						if (error != 0) {
							this->errors_count += 1;
							recalculateWeights(error, features);
						}
					}
					this->epochs += 1;
				}
				while ((this->errors_count > 0) && (epochs < epochs_threshold));
			}

			void train_from_csv (const std::string &filename) {
				std::ifstream data_file(filename);
				
				int gender;
				std::vector<std::pair<std::vector<double>, int>> training_dataset;

				if (data_file.is_open()) {
					while (data_file) {
						std::vector<double> features;
						double feature;
						for (int i=0; i<this->dimensions; i++) {
							data_file >> feature;
							features.push_back(feature);
						}

						//getting the target gender as last column
						data_file >> gender;	


						//debugging
						// Utils::printVector<double>(features);
						
						training_dataset.push_back(std::make_pair(features, gender));
					};
				}
				data_file.close();
				this->train(training_dataset);
			}
				
			int predict (const std::vector<double> &validation_sample) const {
				return stepFunction(validation_sample);
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

			int getErrorsCount () const {
				return this->errors_count;
			}

			std::vector<double>&& getWeights () {
				return static_cast<std::vector<double>&&>(this->weights);
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

		std::cout << std::endl;
		// 7772 is the number of prototypes in the .csv file providing the training data
		std::cout << "Accuracy: " << ((507 - p.getErrorsCount()) / 507.0 ) * 100.0 << "%" << std::endl;

		return stream;
	}

}
