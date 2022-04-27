#include "climb_chromosome.hh"
#include <iostream>
#include <algorithm>



void ClimbChromosome::mutate() {
    double current_fitness = get_fitness();
    std::uniform_int_distribution<> distrib(0, order_.size()-1);
    unsigned int p = distrib(generator_);
    int to_swap_before = p-1;
    int to_swap_after = p+1;
    if (p==0){
        to_swap_before = (order_.size()-1);
    }
    if (p==order_.size()-1){
        to_swap_after = 0;
    }
    std::swap(order_[p], order_[to_swap_before]); //swapping before
    double before_fitness = get_fitness();
    double best_fitness  = std::max(before_fitness, current_fitness);
    std::swap(order_[p], order_[to_swap_before]); //making original vector
    std::swap(order_[p], order_[to_swap_after]); //swapping after
    double after_fitness = get_fitness();
    best_fitness  = std::max(best_fitness, after_fitness);
    std::swap(order_[p], order_[to_swap_after]); //making original vector
    if (best_fitness == before_fitness){
        std::swap(order_[p], order_[to_swap_before]); //swapping before
    }
    if (best_fitness == after_fitness){
        std::swap(order_[p], order_[to_swap_after]); //swapping after
    }

}
