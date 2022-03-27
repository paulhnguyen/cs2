
#include <list>
#include <memory>
#include "hforest.hh"
#include <iostream>
#include <algorithm>


bool compare_trees(HTree::tree_ptr_t t1, HTree::tree_ptr_t t2) {
    return t1->get_value() > t2->get_value();
}
HForest::HForest(){

    forest_ = {};
}

HForest::~HForest(){
}
unsigned HForest::size() const{ // return how many trees are in the forest.
    return this->forest_.size();
}
void HForest::add_tree(HTree::tree_ptr_t tree){ // Take a pointer to an HTree (of type HTree::tree_ptr_t) and add it to the forest.
    this->forest_.push_back(tree);
}
HTree::tree_ptr_t HForest::pop_tree(){ //return a pointer to the HTree with the lowest value in the root node, and remove it from the forest.
    if (this->forest_.size() == 0){
        return nullptr;
    }
    std::make_heap(this->forest_.begin(), this->forest_.end(), compare_trees);
    auto min_pointer = this->forest_.front();
    this->forest_.erase(this->forest_.begin());
    return min_pointer;
}
