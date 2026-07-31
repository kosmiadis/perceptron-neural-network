#include "Sample.h"

namespace Utils {

	double stepFunction(const Sample &sample, const Sample &weights, double bias) {
		return (dotProduct(weights, sample) + bias) >= 0 ? 1 : 0;
	}
	
	double dotProduct (const Sample &s1, const Sample &s2) {
		double sum = 0;
		for (size_t i=0; i<s1.size(); i++) {
			sum += s1[i] * s2[i];
		}
		return sum;
	}

}
