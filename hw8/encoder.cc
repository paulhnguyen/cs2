#include <iostream>
#include <fstream>
#include "bitio.hh"
#include "huffman.hh"

int main(int argc, char **argv){
    for (int i = 1; i < argc; ++i ){
        std::ifstream inputfile(argv[i]);
        
        std::string outputname(argv[i]);
        outputname = outputname + ".comp";
        std::cout << outputname << std::endl;
        std::ofstream outputfile(outputname);
            

        BitOutput BitOutput(outputfile);
        Huffman::bits_t bits;
        Huffman encode_tree;
        
        char symbol;

        while(inputfile.get(symbol)){
            auto bits = encode_tree.encode(symbol);
            for (auto i : bits){
                BitOutput.output_bit(i);
            }
        }
        for (auto i : encode_tree.encode(encode_tree.HEOF)){

            BitOutput.output_bit(i);
        }   
    }
}