#pragma once
#include <vector>

namespace Utils {
	double dotProduct (const std::vector<double> &s1, const std::vector<double> &s2) {
		double sum = 0;
		for (size_t i=0; i<s1.size(); i++) {
			sum += s1[i] * s2[i];
		}
		return sum;
	}

	template <typename T>
	void printVector (const std::vector<T> &vec) {
		for (size_t i=0; i<vec.size(); i++) {
			std::cout << vec[i] << " ";
		}
		std::cout << std::endl;
	}
}
