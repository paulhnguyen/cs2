Paul Nguyen and Michael Huynh

How to build:
Make and run with corresponding test files. 

Adaptive Huffman Encoding:
We implement the Adaptive Huffman encoding and decoding algorithms following the homework instructions. From moodle:

The algorithm for encoding a character (symbol) c is summarized as follows:
* Build a Huffman tree from scratch, given the current frequency table (that you'll have to maintain in a separate data member).
* Find the path to c in the Huffman tree from the root.
* Convert the path of LEFTs and RIGHTs to zeros and ones, which will be returned as a sequence of bits (type bits_t).
* Increment the frequency table by adding one to c's count.
Similarly, the algorithm for decoding a single bit b at a time into a symbol works as follows:
* If this is the first bit in a sequence (Huffman tree not yet computed), build a Huffman tree from scratch, given the existing frequency table (see below), and start from the root node.
* Otherwise, start from the previous node you've computed.
* Compute the next node as either the left or right child of the current node, depending on the bit value.
* If this is an intermediate node (not a leaf), you will return a negative number for a symbol. Otherwise, you're a leaf, pointing to an actual symbol, which you will return.
* Eventually, the current node will be a leaf, at which point a real character c will be returned, and you can reset the Huffman tree to nullptr to remember that next bit starts a new sequence. Additionally, increment the frequency table for c.

We perform the standard test cases given to us, because this project was hard. 

Bit I/O
From Moodle:
A BitInput object is meant to be used for reading bits from a file one at a time, and a BitOutput object for writing. The destructor cleans up any pending file operations.
In our destructor for BitOutput, we put when the current index is greater than 0. This covers the cases when we aren’t inputting a multiple of 8, which is covered in the actual output_bit function. We again perform the standard test cases.

Encoder/Decoder
Encoder takes another filename as a command-line argument. It then reads and compresses the file into an output file of the same name with a .comp suffix. Decoder takes in a filename as well, reads it, and decompressed it into a file with the same name and a .plaintext suffix. We use the huffman and Bit I/O algorithms to encode and decode text. 

Compression Tests
We provide 5 text files and compress/decompress them: spiderman, sonic, french mickey mouse, charizard, and a sitting man.


| Text File  | Raw Size  | Compressed Size  | Matches? | 
|---|---|---|---|---|
|   |   |   |   |   |
|   |   |   |   |   |
|   |   |   |   |   |

