#include "htree.hh"
#include "hforest.hh"
#include <iostream>
#include <cassert>



HTree::tree_ptr_t tree(HTree::key_t key, HTree::value_t value){
    auto root = std::make_shared<HTree>(key, value);
    return root;
} 

void forest1(){
    HForest forest_test;
    auto tree1 = tree(1,1);
    auto tree2 = tree(2,2);
    auto tree3 = tree(3,3);
    auto tree4 = tree(4,4);
    auto tree5 = tree(5,5);

    forest_test.add_tree(tree1);
    forest_test.add_tree(tree2);
    forest_test.add_tree(tree3);
    forest_test.add_tree(tree4);
    forest_test.add_tree(tree5);
    
    assert(forest_test.size() == 5);

    auto removed_tree = forest_test.pop_tree();
    std::cout << "Removed Tree: " << removed_tree->get_key() << std::endl;
    // assert(forest_test.pop_tree() == tree1);

    assert(forest_test.size() == 4);
    
}


int main(){

    forest1();
    return 0;

}