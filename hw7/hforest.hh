#pragma once
#include "htree.hh"
#include <vector>
#include <iostream>

class HForest{
    public:
        using forest_t = std::vector<HTree::tree_ptr_t>;
        HForest();
        ~HForest();

        unsigned size() const;

        void add_tree(HTree::tree_ptr_t tree);

        HTree::tree_ptr_t pop_tree();
    private:
        forest_t forest_;
};