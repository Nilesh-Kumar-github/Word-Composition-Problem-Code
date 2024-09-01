
# Compound Word Finder



## Overview
This program is designed to identify the longest and second-longest compound words from a list of words in a text file. A compound word is defined as a word that can be constructed by concatenating two or more words from the same list. The program reads the words from a specified input file, processes them to find compound words, and then outputs the longest and second-longest compound words found.
## Design Decisions and Approach

1. Data Structures:

std::unordered_set<std::string>: Used for storing words to allow O(1) average time complexity for lookups. This is essential for efficiently checking if a prefix or suffix is a valid word.
std::vector<std::string>: Used to store the list of words in their original order before sorting them by length. This allows processing the longest words first, which optimizes the search for the longest compound word.

2. Algorithm:

The program begins by reading all the words from the input file and storing them in both a vector and an unordered set.
The words are then sorted in descending order of length to prioritize checking the longest words first.
For each word, the program checks if it can be split into valid prefixes and suffixes, which are themselves words in the list. This is done using the isCompoundWord function, which also employs memoization to avoid redundant calculations.
Once the longest and second-longest compound words are identified, the program outputs them along with the time taken for processing.

3. Optimization:

Memoization: A memoization technique is used to store words that have already been identified as compound words, reducing the time complexity for subsequent checks.
Early Exit: The program stops processing once the longest and second-longest compound words have been found, reducing unnecessary computations.

## Execution Steps

1. Prepare the Input File:

Create a text file named Input_01.txt (or modify the filename in the code) containing a list of words, each on a new line. For example:

cat
cats
catsdogcats
catxdogcatsrat
dog
dogcatsdog
hippopotamuses
rat
ratcatdogcat

2. Compile the Program:

Use a C++ compiler to compile the program. For example, using g++:
g++ -o compound_word_finder compound_word_finder.cpp

3. Run the Program:

Execute the compiled program:
./compound_word_finder

4. View the Results:

The program will output the longest and second-longest compound words, along with the time taken to process the file.

## Conclusion
This program efficiently finds the longest compound words in a given list using a combination of data structures and algorithmic techniques. The use of unordered_set for quick lookups, sorting for prioritizing longer words, and memoization for reducing redundant calculations are key aspects of the design that ensure optimal performance.