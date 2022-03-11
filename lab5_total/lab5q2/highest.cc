#include <iostream>
#include <initializer_list>

const int* highest(int val, const int* start, const int* finish){
    const int* end_array = finish - 1; // finish is too far past the array.
    if (*start > val){ // if the beginning of array is bigger than val, then val not in array
        return nullptr;
    }
    if (*end_array < val){ // if the end of the array is smaller than val, then val not in array
        return nullptr;
    }


    if (*end_array == val){ // if value is located at the end of array, return end of array
        return end_array;
    }
    const unsigned int dist = end_array - start; //finds distance between start and finish pointers
    const int* midpoint = start + (dist / 2); //finds midpoint
    // std::cout << "Start: " << *start << "\n";
    // std::cout << "midpoint: " << *midpoint << "\n";
    // std::cout << "Finish: " << *finish << "\n";
    // std::cout << "end_array: " << *end_array << "\n";
    if (*midpoint < val){ //if midpoint is less than val, look at top half of array
        return highest(val, midpoint + 1, finish);
    }
    else { //if midpoint is geq than val, look at bottom half of array
        return highest(val, start, midpoint + 1);
    }

}


int main()
{
    const int DATA_LEN = 9;
    const int data[DATA_LEN] = {1, 1, 1, 4, 4, 5, 6, 7, 10 };

    if (DATA_LEN <= 0){ // Weird case, PRINT ARRAY LEN 0 AND END FUNC
        std::cout << "Invalid Array Size \n \n";
        return 0;
    }
    for (auto search : { 0, 1, 2, 4, 7, 8, 9, 10, 11 }) {
        // std::cout << "Val: " << search << "\n";
        const auto where = highest(search, data, data + DATA_LEN);
        std::cout << "Index of elem: " << search << " is: ";
        if (where == nullptr) {
            std::cout << "not found!" << std::endl;
        } else {
            std::cout << (where-data) << std::endl;
        }

    }
    return 0;

}
