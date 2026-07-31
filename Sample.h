#pragma once
#include <vector>

class Sample {
	private:
		std::vector<double> features;
	public:
		Sample(): features{} {};
		
		Sample(std::vector<double> features_vector): features{ features_vector } {};
		Sample(std::initializer_list<double> features_list): features{features_list} {};

		double operator[](int index) const {
			return this->features[index];	
		}
        
		size_t size () const {
			return this->features.size();
		}	
};


