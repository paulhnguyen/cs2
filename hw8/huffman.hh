/*
 * Huffman: a class to encode and decode symbols based on adaptive Huffman coding
 * https://en.wikipedia.org/wiki/Huffman_coding
 */

#pragma once

#include <climits>
#include <vector>
#include <unordered_map>
#include "htree.hh"
#include "hforest.hh"

class Huffman {
 public:
  // Maximum number of symbols we need to encode (a symbol fits in a char) + EOF
  static const int ALPHABET_SIZE = (1 << CHAR_BIT) + 1;  // (2 ** 8) + 1      
  static const int HEOF = ALPHABET_SIZE - 1;  // Special symbol to denote end of file

  using bits_t = std::vector<bool>;

  Huffman();
  ~Huffman();
  Huffman(const Huffman&) = delete;               // prevents the compiler from generating a copy construtor 
  Huffman(Huffman&&) = delete;                    //
  Huffman& operator=(const Huffman&) = delete;    //
  Huffman& operator=(Huffman&&) = delete;         //

  // Encode a symbol into a sequence of bits, then update frequency table.
  bits_t encode(int symbol);

  // Decode a single bit into a symbol. If no symbol can be unmabiguously decoded
  // without additional bits, returns a negative value.
  // Subsequent calls with more bits should eventually resolve to either
  // a character symbol or HEOF.
  // Finally, updates the frequency table with this additional symbol.
  int decode(bool bit);
  HTree::tree_ptr_t create_huffman();
  private:
    using freq_table_t = std::vector<unsigned int>;
    freq_table_t freq_table_;
    HTree::tree_ptr_t current_tree_;

};
