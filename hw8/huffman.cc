#include <iostream>
#include "huffman.hh"

Huffman::Huffman():
freq_table_(ALPHABET_SIZE)
{
    //freq_table_t freq_table_(ALPHABET_SIZE);
    int value = 0;
    std::fill(freq_table_.begin(), freq_table_.end(), value);
    // for (unsigned int i=0; i< ALPHABET_SIZE - 2; i++){
    //     freq_table[i] = 0;
    // }
    freq_table_[HEOF] = 1;
    current_tree_ = nullptr;
}

Huffman::~Huffman(){
}

HTree::tree_ptr_t Huffman::create_huffman(){
    HForest hforest;
    for(unsigned int i = 0; i < ALPHABET_SIZE; i++){
        hforest.add_tree(std::make_shared<HTree>(i, freq_table_[i]));
    }
    while (hforest.size() > 1){
        auto tree1 = hforest.pop_top();
        auto tree2 = hforest.pop_top();
        auto total = tree1->get_value() + tree2->get_value();
        hforest.add_tree(std::make_shared<HTree>(-1, total, tree1, tree2));
    }
    return hforest.pop_top();
}
Huffman::bits_t Huffman::encode(int symbol){
    HTree::tree_ptr_t huffman_tree = this->create_huffman(); 
    HTree::possible_path_t path = huffman_tree->HTree::path_to(symbol);
    bits_t bits_vector;
    for (auto dir : *path){
        if (dir  == HTree::Direction::LEFT){
            bits_vector.push_back(0);
        }
        else{
            bits_vector.push_back(1);
        }
    }
    freq_table_[symbol] = freq_table_[symbol] + 1;
    return bits_vector;
}

int Huffman::decode(bool bit){
    if (current_tree_ == nullptr){
        current_tree_ = create_huffman();
    }
    if (bit == 0){
        current_tree_ = current_tree_->get_child(HTree::Direction::LEFT);
    }
    if (bit == 1){
        
        current_tree_ = current_tree_->get_child(HTree::Direction::RIGHT);
    }
    auto current_key = current_tree_->get_key();
    if (current_key > 0){
        freq_table_[current_key] = freq_table_[current_key] + 1;
        current_tree_ = nullptr;
        return current_key;
    }
    return -1;
}