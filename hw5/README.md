Paul Nguyen's HW 5 

Apologies in advance if this Readme isn't up to standard, I missed lab this week, so I'll update it after chatting with Eitan hopefully.

My estimates for $pi$:
10: 3.52
100: 3.1812
1000: 3.14554
10000: 3.14199


I would expect the run time for this function to be $O(N^2)$, since it consists of two for loops, one nested within the other, and both running $N$ times. 

Time for running gridpi for various N:
10 : real	0m0.013s
100: real	0m0.007s
1000: real	0m0.012s
10000: real	0m0.530s


Compiled gridpi2 run times (from the pi_comp.cc file):
10 : real	0m0.008s
100: real	0m0.009s
1000: real	0m0.014s
10000: real	0m0.471s

this is more similar to what I'd expect. It's not as dramatic of a shift as I would have expected though.
I would have expected similar ratios.. ie if 10 took ~.01 sec, 100 should take ~.1 sec, and 1000 should take ~.1 sec 
