#include "Sample.h"

namespace Utils {
	double dotProduct (const Sample &s1, const Sample &s2) {
		double sum = 0;
		for (size_t i=0; i<s1.size(); i++) {
			sum += s1[i] * s2[i];
		}
		return sum;
	}
}
