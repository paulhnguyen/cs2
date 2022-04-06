#include <iostream>
#include <fstream>
#include "bitio.hh"
#include "huffman.hh"

int main(int argc, char **argv){
    for (int i; i < argc; ++i ){
        std::ifstream inputfile(argv[i]);
        
        std::string outputname(argv[i]);
        outputname = outputname + ".plaintext";
        std::ofstream outputfile(outputname);
        std::ifstream inputstream(argv[i]);

        BitInput BitInput(inputstream);
        int key = -1;
        Huffman decode_tree;

        while (key !=decode_tree.HEOF){
            auto bit = BitInput.input_bit();
            key = decode_tree.decode(bit);
            if (key != decode_tree.HEOF){
                outputfile.put(key);
                key = -1;
            }
            else if (key == decode_tree.HEOF){
                break;
            }
        }
    }
}