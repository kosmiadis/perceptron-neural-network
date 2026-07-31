#pragma once
#include <chrono>
#include <random>
#include <ctime>

class GenRandomReal {
    private:
        std::default_random_engine engine;
        std::uniform_real_distribution<double> distribution;
    public:
        GenRandomReal (double low, double high): distribution {low, high} {
            engine.seed(time(NULL));
        };

        double operator()() {
            return distribution(engine);
        }
};
