/*
 * A pair of simple classes tu perform stream I/O on individual bits.
 */
#include "bitio.hh"
#include <iostream>
#include <cassert>

BitInput::BitInput(std::istream& is)
  : is_(is), current_index_(0), bit_seq_(0)
  {}


bool BitInput::input_bit(){
    if (current_index_ == 0){
        bit_seq_ = is_.get();
    }
    auto tmp_seq  = bit_seq_ >> (current_index_);
    current_index_++;
    if (current_index_ == 8){
        current_index_ = 0;
    }
    auto bit = tmp_seq & 1;
    return bit;
    // return bit_seq_ & (1 << current_index_);

    
}



BitOutput::BitOutput(std::ostream& os)
    : os_(os), current_index_(0), char_vec_(0)
    {}


BitOutput::~BitOutput(){
    // read on the osstream library online
    // In the case where the number of bits is not a multiple of 8, 
    // we choose to fill the rest of the char vector with 0's and output the whole character vector so that the bits arent lost.

    if (current_index_ > 0){
        os_.put(char_vec_);
    }
}

void BitOutput::output_bit(bool bit){
    char_vec_ = (char_vec_) | (bit << current_index_);

    current_index_++;
    if (current_index_ == 8){ // this implementation only put's every 8 bits. 
        os_.put(char_vec_);
        current_index_ = 0;
        char_vec_ = 0;
    }
    

    return;
}
