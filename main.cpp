#include <iostream>
#include "Perceptron.h"
#include <vector>
#include "Utils.h"

using namespace std;

//passing lvalue reference as features
void makePrediction (const PerceptronModel::Perceptron &model, const vector<double> &features) {
	int prediction = model.predict(features);
	cout << "Classified as " << (prediction == 1 ? "Male" : "Female") << endl;
}

int main (int argc, char* argv[]) {
	PerceptronModel::Perceptron model(24);

	model.train_from_csv("data.csv");
	cout << model << endl;

	std::vector<double> male_1 {
    	42.9, 30, 31.5, 17.7, 28, 13.1, 10.4, 18.8,
    	14.1, 106.2, 89.5, 71.5, 74.5, 93.5, 51.5,
    	32.5, 26, 34.5, 36.5, 23.5, 16.5,
    	21, 65.6, 174
	};

	///find the dot product of a male with the trained model
	makePrediction(model, male_1);

	std::vector<double> female_1 {
    	38.7, 24.8, 29.6, 16.9, 26.5, 12.2, 9.8, 17.5,
    	13.2, 98.4, 82.1, 68.3, 72.6, 89.7, 49.2,
    	30.1, 24.8, 32.7, 34.8, 22.1, 15.3,
    	28, 58.4, 162
	};

	makePrediction(model, female_1);

	return 0;
}
