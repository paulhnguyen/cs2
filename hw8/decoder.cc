#include <iostream>
#include <fstream>
#include "bitio.hh"
#include "huffman.hh"

int main(int argc, char **argv){
    for (int i= 1; i < argc; ++i ){
        std::ifstream inputfile(argv[i]);
        
        std::string outputname(argv[i]);
        outputname = outputname + ".plaintext";
        std::ofstream outputfile(outputname);

        BitInput BitInput(inputfile);
        // int key = -1;
        int key = -1;
        Huffman decode_tree;

        while (key !=decode_tree.HEOF){
            while(key < 0){
                key = decode_tree.decode(BitInput.input_bit());
            }

            if(key == Huffman::HEOF){
                break;
            }
            else{
                outputfile.put(key);
                key =-1;
            }
        }
    }
}