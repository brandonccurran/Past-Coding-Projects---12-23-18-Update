For this assignment, you will write a program in C++ that generates an “inverted index” of all the words in a list of text files. (See http://en.wikipedia.org/wiki/Inverted_index for more details.) 

Your inverter should output to a string all of the words from all of the inputs, in “alphabetical” order, followed by the document numbers in which they appear, in order. 

Alphabetical is defined as the order according to ascii. So “The” and “the” are separate words, and “The” comes first. Only certain words should be indexed. words are anything that is made up of only alpha characters, and not numbers, spaces, etc. “Th3e” is two words, “Th” and “e”.

Files are incrementally numbered, starting with 0. Only valid, openable files should be included in the count. (is_open comes in handy here)

Your program should absolutely not produce any other output. Extraneous output, or output formatted incorrectly (extra spaces etc.) will make the autograder mark your solution as incorrect. Please leave yourself extra days to work these problems out.


All credit for this assignment's starter code and documentation belongs to Tim Richards
https://www.cics.umass.edu/faculty/directory/richards_tim