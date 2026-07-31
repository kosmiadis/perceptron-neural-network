#include <iostream>
#include <vector>

using namespace std;


class Sample {
	private:
		vector<double> features;
	public:
		Sample(std::initializer_list<double> features_vector): features{features_vector} {};

		double operator[](int index) const {
			return this->features[index];	
		}
		
		size_t size () const {
			return this->features.size();
		}	
};

double dotProduct (const Sample &s1, const Sample &s2) {
	double sum = 0;
	for (size_t i=0; i<s1.size(); i++) {
		sum += s1[i] * s2[i];
	}
	return sum;
}

int main (){
	
	Sample sample1 {{ 1, 0, 1 }};
	Sample sample2 {{ 0, 10, 3 }};

	double dot = dotProduct(sample1, sample2);
	cout << "The dot product is: " << dot << endl;	

	return 0;
}
