/*
 * HTree: a class to represent a tree node with two values: a key
 * and a value.
 */

#include "htree.hh"
#include <list>
#include <memory>
#include <iostream>

using namespace std;

// Return an optional list of directions from root to a node of a given key.
// If key not contained in this tree, returns nullptr
//HTree::possible_path_t
/*
HTree::path_to(key_t key) const
{
  return nullptr;
}
*/
HTree::HTree(key_t key,
            uint64_t value,
            HTree::tree_ptr_t left,
            HTree::tree_ptr_t right)
            //:key_(key)
            :key_(key), value_(value), left_(left), right_(right)
            {}

HTree::~HTree(){
}

int HTree::get_key() const { return key_; }

uint64_t HTree::get_value() const { return value_; }

HTree::tree_ptr_t HTree::get_child(Direction dir) const{

    if (dir == Direction::LEFT){
        if (left_ == nullptr){
            return nullptr;
        }
        else {
            return left_;
        }
    }
    if (dir == Direction::RIGHT){
        if (right_ == nullptr){
            return nullptr;
        }
        else {
            return right_;
        }
    }
    else {
      return nullptr;
    
    }
}
/*
HTree::possible_path_t HTree::path_list(key_t key, path_t path){
    if (!this){
      return nullptr;
    }
    if (key_ == key){
      return *path;
    }
    possible_path_t left_path = left_->path_list( key, path + );
    possible_path_t right_path = right_->path_list(key, path.push_back(Direction::RIGHT));
    
    
    if (left_path == "-" && right_path == "-"){
        return "-";
    }
    if (left == "-" && right != "-"){
        return right;
    }
    else{
        return left;
    }
}
*/
HTree::possible_path_t HTree::path_to(key_t key) const{
    
    //  HTree::path_t path = { };
    if (this->key_ == key){
      auto list_of_directions = make_unique<path_t>();
      return (list_of_directions);              // Supposed to return a pointer to the path
    }
    possible_path_t left_res = left_->path_to(key);
    if (left_res != nullptr){
      left_res->push_front(Direction::LEFT); // builds the path, but left_res is pointer not a list
      return left_res;
    }
    possible_path_t right_res = right_->path_to(key);
    if (right_res == nullptr){
      return nullptr;
    }
    else{
      right_res->push_front(Direction::RIGHT); // builds the path, but right_res is pointer not a list
      return right_res;
    }


}

