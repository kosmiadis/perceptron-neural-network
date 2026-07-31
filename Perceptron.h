#pragma once
#include <iostream>
#include "Sample.h"
#include "GenRandom.h"

namespace PerceptronModel {
	class Perceptron {
		private:
			std::vector<double> weights;
			double bias;
			double learning_step; //learning step
			int dimensions; //dimensions

		public:
			//constructor gets the features dimension as a parameter	
			Perceptron(int d): dimensions{d} {

				GenRandomReal gen_step{0.01, 0.1}, gen_bias{0.01, 1.00 }, gen_weight{-1, 1};

				//generate random starting learning step
				this->learning_step = gen_step();

				//generate random starting bias
				this->bias = gen_bias();
				
				//initialize weights
				for (int i=0; i<d; i++) {
					weights.push_back(gen_weight());
				}
			};

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
