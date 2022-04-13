HW9: TSP (Random Search)
Paul Nguyen and Michael Huynh

This folder contains the code and results from the random search implementation of the traveling salesman problem.



- operator>> (std::istream&, Cities&) to allow for the reading  / filling of a Cities object from a stream. 
- operator<< (std::ostream&, Cities&) to allow for the outputting of a Cities object to a stream.
- total_path_distance. Computes the total distance of traversing all the cities in the order defined by the permutation, including going back from the last city in the permutation to the first one.
- reorder. returns a new Cities object where the internal representation of the cities reflects the order as indexed by the permutation.
- random_permutation. generates and returns a new permutation of all the numbers from 0 to len-1 (with no skipped or repeated indices). Our algorithm begins with two vectors. The first is a random vector, to be filled with the random permutation, and the other is the list of available numbers. We select a random number from 0 to the size of the available numbers - 1, which represents which index from available numbers, selecting a number from avail_num, which we add to the random vector. Then we remove the number from avail_num and begin again, until the size of avail_num is 0.
- Randomized search: Write a new file called tsp.cc with a main() function that will perform the actual search.

Notes: Our shortest city file result is actually called shortest2.tsv due to some file issues.
shortest2.gif contains most efficient path found by random search.
speed.gif containts the iterations in which random search found a more efficient path, and how long that path is.
