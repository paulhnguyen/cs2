#include "cities.hh"
#include <iostream>
#include <fstream>
#include <limits>

int main(int argc, char **argv){
    for (int i = 1; i < argc; ++i){
        std::ifstream inputfile(argv[i]);
        Cities city;
        
        int iterations = 1000000;
        inputfile >> city;

        unsigned number_of_cities = city.size();
        Cities::permutation_t order = city.random_permutation(number_of_cities);

        Cities best_city;
        double best_distance = city.total_path_distance(order);
        std::cout << "0" << "\t" << best_distance << std::endl;
        for(int j = 1; j < iterations; ++j){
            if(i%1000 == 0){
                std::cout << j << std::endl;
            }
            order =  city.random_permutation(number_of_cities);
            city = city.reorder(order);
            double total_distance = city.total_path_distance(order);
            if (total_distance < best_distance){
                best_distance = total_distance;
                best_city = city;
                std::cout << j << "\t" << best_distance << std::endl;
            }
        }
    
    std::ofstream outstream;
    outstream.open("shortest2.tsv");
    outstream << best_city;
    outstream.close();
    }
    return 0;
}