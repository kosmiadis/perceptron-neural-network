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
			int epochs;
			std::vector<double> weights;
			double bias;
			double learning_step; //learning step
			int dimensions; //dimensions

		public:
			//constructor gets the features dimension as a parameter	
			Perceptron(int d): dimensions{d}, epochs{2} {

				GenRandomReal gen_step{0.01, 0.1}, gen_bias{-1, 1 }, gen_weight{-1, 1};

				//generate random starting learning step
				this->learning_step = gen_step();

				//generate random starting bias
				this->bias = gen_bias();
				
				//initialize weights
				for (int i=0; i<d; i++) {
					//weights.push_back(gen_weight());
					weights.push_back(0);
				}
			};

			int stepFunction(const std::vector<double> &sample, const std::vector<double> weights) {
				double dp = Utils::dotProduct(weights, sample) + this->bias;
				std::cout << "Dot product: " << dp << std::endl;
				return dp > 0 ? 1 : 0;
			}
	
			void recalculateWeights (double error, std::vector<double> features ) {
				for (int i=0; i<weights.size(); i++) {
					weights[i] = weights[i] + learning_step*error*features[i];
				}
			}
				
			/*
				The training dataset consists of pairs, in which the first element is the sample features (vector) 
				and the second element is the correct target (label)
			*/
			void train (std::vector<std::pair<std::vector<double>, int>> training_set ) {
				for (int i=0; i<epochs; i++) {
					for (auto &sample: training_set) {
						std::vector<double> features = sample.first; 
						int target = sample.second;
						int y = stepFunction(features, this->weights);
						double error = getError(target, y);	
						if (error != 0) {
							recalculateWeights(error, features);
						}
					}
				}		
			}
				
			int predict (std::vector<double> validation_sample) {
				for (auto v: validation_sample) {
					std::cout << v << ", ";
				}

				return stepFunction(validation_sample, weights);
			}

			std::vector<double> getWeights () const {
				return weights;
			}

			double getLearningStep () const {
				return learning_step;
			}
	};

	std::ostream &operator<<(std::ostream &stream,  const Perceptron &p) {
		std::cout << "Weights: "; 
		for (auto &x: p.getWeights()) {
			std::cout << x << ", ";
		}
		std::cout << std::endl;
		std::cout << "Learning step: " << p.getLearningStep();
		std::cout << std::endl;
		return stream;
	}

}
