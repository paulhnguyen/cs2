Michael Huynh and Paul Nguyen

How how build:
Just use make and run each part with either ./test_htree or ./test_hforest

Part 1: HTree
For the get_child function, we took in the input and if there exists a node in that direction and there is, we return the node. 
Otherwise, we return nullptr. For the path_tp function, we wrote the function recursively to call on itself with all the possible
paths, going left or right, until we found a node with the same key as the key inputted and we returned the path that was taken
to get to that node. 

Part 2: HForest
To check the size of the forest, we just used the built-in function .size() to check the size of our forest. For the add_tree,
we just used the .push_back funtion to add it to the forest. For the pop_tree function, we included a base case for an empty
forest. Otherwise, we created a heap that would return the front of the heap, which was the smallest. Before doing so, we saved 
it into the return variable and erased it from the forest then returned it.
