#include "cities.hh"
#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <random>
#include <utility>

using permutation_t = std::vector<unsigned int>;

permutation_t random_permutation(unsigned len) {
    permutation_t random_vec;
    std::vector<unsigned int> avail_num;
    for (unsigned int i = 0; i < len; i++) // initializes available numbers vector
    {
        avail_num.push_back(i);
    }
    for (unsigned int i = 0; i < len; i++) // randomly selects an index, adds avail_num[i] to random_vec, removes num from avail_num
    {
        std::uniform_int_distribution<int> runif(0, avail_num.size() - 1);
        typedef std::mt19937 rng_type;
        rng_type rng;
        unsigned int special_num = runif(rng);
        random_vec.push_back(avail_num[special_num]);
        avail_num.erase(avail_num.begin() + special_num);
    }
    
    return random_vec;
}

int main(){
    // std::ifstream fin = std::ifstream("five.tsv", std::ifstream::in);
    // Cities cities;
    // fin >> cities;
    // std::cout << cities.total_path_distance({ 0, 1, 2, 3, 4 }) << "\n"; // Should be 48.8699
    // std::cout << cities.total_path_distance({ 3, 2, 4, 0, 1 }) << "\n"; // Should be 53.43

    // return 1;

    Cities::permutation_t vec = random_permutation(10);
    for (unsigned int i = 0; i < 10; i++) // initializes available numbers vector
    {
        std::cout << vec[i] << std::endl;
    }
    Cities::permutation_t vec2 = random_permutation(10);
    for (unsigned int i = 0; i < 10; i++) // initializes available numbers vector
    {
    std::cout << vec2[i] << std::endl;
    }
    return 0;

}