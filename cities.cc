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

Cities::Cities(){
    city_list_ = {};
}

Cities::~Cities(){
}

std::istream& operator>>(std::istream& is, Cities& obj){
    while (!is.eof()){
        std::string c;
        getline(is ,c, '\n'); // puts line into string c
      
        std::string delimiter = " "; //https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
        size_t pos = 0;
        std::string x;
        std::string y;
        pos = c.find(delimiter);
        if (pos == std::string::npos){
            break;
        }
        x = c.substr(0, pos);
        y = c.substr(pos + 1);
        
        std::pair<int, int> PAIR;
        PAIR = std::make_pair(stoi(x), stoi(y));

        obj.city_list_.push_back(PAIR);
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Cities& obj){
    for(unsigned int i=0; i < obj.city_list_.size(); i++){
        os << obj.city_list_[i].first;
        os << " ";
        os << obj.city_list_[i].second;
        os << '\n';
}
    return os;
}

double get_dist(std::pair<int, int> start_city, std::pair<int, int> end_city){
    double x_part = pow(start_city.first - end_city.first, 2); 
    double y_part = pow(start_city.second - end_city.second, 2);
    return sqrt(x_part + y_part);
}


void Cities::add_city(coord_t new_city)
{
    city_list_.push_back( new_city );
}   


Cities Cities::reorder(const permutation_t& ordering) const{
    Cities new_city_object ;
    std::vector<coord_t> new_city_list;
    for (unsigned int i=0; i < ordering.size(); i++){
        new_city_object.add_city(city_list_[ordering[i]]);
    }
    return new_city_object;
}

double Cities::total_path_distance(const permutation_t& ordering) const{
    double total_dist = 0;
    coord_t first_city = city_list_[ordering[0]];
    for (unsigned int i=0; i < ordering.size() - 1; i++){
        coord_t current_loc = city_list_[ordering[i]];
        coord_t next_loc = city_list_[ordering[i+1]];
        total_dist = total_dist + get_dist(current_loc, next_loc);
    }
    coord_t last_city = city_list_[ordering[ordering.size()-1]];
    total_dist = total_dist + get_dist(last_city, first_city);
    return total_dist;
}

// That generates and returns a new permutation of all the numbers from 0 to len-1 (with no skipped or repeated indices)

permutation_t Cities::random_permutation(unsigned len) {
    permutation_t random_vec;
    std::vector<unsigned int> avail_num;
    std::random_device rd;
    std::mt19937 rng(rd());
    for (unsigned int i = 0; i < len; i++) // initializes available numbers vector
    {
        avail_num.push_back(i);
    }
    for (unsigned int i = 0; i < len; i++) // randomly selects an index, adds avail_num[i] to random_vec, removes num from avail_num
    {
        
        std::uniform_int_distribution<int> runif(0, avail_num.size() - 1);
        std::random_device rd;
        std::mt19937 rng(rd());
        unsigned int special_num = runif(rng);
        random_vec.push_back(avail_num[special_num]);
        avail_num.erase(avail_num.begin() + special_num);
    }
    
    return random_vec;
}
int Cities::size() {
    return city_list_.size();
}
