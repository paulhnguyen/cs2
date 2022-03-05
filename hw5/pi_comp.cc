#include <iostream>
#include <cmath>
using namespace std;

// idea: square has x and y aspect
// while loop for x from 0:N
// while loop for y from 0:N
// calculate the hyp for x, y.. should be leq N
// if hyp(x,y) leq N, then add 1 to sum,
// take sum, divide by total number of points (N^2), and multiply by 4 to get estimate

constexpr double gridpi2(uint N){ // helper function that returns a estimate, takes in one input, N
    double sum = 0;
    double total = 0; // going to have this 'total' counter. should equal to N^2.. just safeguarding code
    for(double x = 0; x <= N-1; ++x){ // iterate x from 0:N
        for(double y = 0; y <= N-1; ++y){ // interate y from 0:N
            ++total;
            if (std::hypot(x, y) <= N){
                ++sum;
            }
        }
    }
    double estimate = sum / total * 4;
    cout << "Sum: " << sum << '\n';
    cout << "Total: " << total << '\n';
    cout << "Estimate: " << estimate << '\n';
    return estimate;
}


int main(){
    cout << "N = 10000 \n" << gridpi2(10000) << '\n';
    //cout << "N = 100 \n" << gridpi2(100) << '\n';
    //cout << "N = 1000 \n" << gridpi2(1000) << '\n';
    //cout << "N = 10000 \n" << gridpi2(10000) << '\n';

    return 0;
}

// estimates:
// 10: 3.52
// 100: 3.1812
// 1000: 3.14554
// 10000: 3.14199

// times: (after running a couple times)
// should be O(N^2)
// 10 : real	0m0.008s
// 100: real	0m0.009s
// 1000: real	0m0.014s
// 10000: real	0m0.471s

// this is more similar to what I'd expect. It's not as dramatic of a shift as I would have expected though.
// I would have expected similar ratios.. ie if 10 took ~.01 sec, 100 should take ~.1 sec, and 1000 should take ~.1 sec 
