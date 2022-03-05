#include <iostream>
#include <cmath>
using namespace std;

// idea: square has x and y aspect
// while loop for x from 0:N
// while loop for y from 0:N
// calculate the hyp for x, y.. should be leq N
// if hyp(x,y) leq N, then add 1 to sum,
// take sum, divide by total number of points (N^2), and multiply by 4 to get estimate

double gridpi(uint N){ // helper function that returns a estimate, takes in one input, N
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
    //cout << "N = 10 \n" << gridpi(10) << '\n';
    //cout << "N = 100 \n" << gridpi(100) << '\n';
    //cout << "N = 1000 \n" << gridpi(1000) << '\n';
    cout << "N = 10000 \n" << gridpi(10000) << '\n';

    return 0;
}

// estimates:
// 10: 3.52
// 100: 3.1812
// 1000: 3.14554
// 10000: 3.14199

// times: (after running a couple times)
// should be O(N^2)
// 10 : real	0m0.013s
// 100: real	0m0.007s
// 1000: real	0m0.012s
// 10000: real	0m0.530s

// not quite what I expected, since N=10 actually had the second longest time.
// would expect the times to increase as N increases.
