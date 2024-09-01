#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <chrono>

bool isCompoundWord(const std::string& word, const std::unordered_set<std::string>& wordSet, std::unordered_set<std::string>& memo) {
    if (memo.find(word) != memo.end()) return true; // If the word is in memo, it's a compound word
    
    for (int i = 1; i < word.size(); ++i) {
        std::string prefix = word.substr(0, i);
        std::string suffix = word.substr(i);
        
        if (wordSet.find(prefix) != wordSet.end()) {
            if (wordSet.find(suffix) != wordSet.end() || isCompoundWord(suffix, wordSet, memo)) {
                memo.insert(word); // Mark this word as a compound word
                return true;
            }
        }
    }
    
    return false; // If no compound form is found, return false
}

int main() {
    std::string inputFileName = "Input_02.txt";
    std::ifstream inputFile(inputFileName);
    
    if (!inputFile) {
        std::cerr << "Error opening input file: " << inputFileName << std::endl;
        return 1;
    }

    std::vector<std::string> words;
    std::unordered_set<std::string> wordSet;
    std::string word;

    while (std::getline(inputFile, word)) {
        words.push_back(word);
        wordSet.insert(word);
    }
    
    inputFile.close();

    std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
        return a.size() > b.size();
    });

    std::unordered_set<std::string> memo;
    std::string longestCompoundWord, secondLongestCompoundWord;

    auto start = std::chrono::high_resolution_clock::now();

    for (const auto& word : words) {
        bool result = isCompoundWord(word, wordSet, memo);
        std::cout << "Checking word: " << word << ", is compound: " << (result ? "Yes" : "No") << std::endl;

        if (result) {
            if (longestCompoundWord.empty()) {
                longestCompoundWord = word;
            } else if (secondLongestCompoundWord.empty()) {
                secondLongestCompoundWord = word;
                break;  // We found both, no need to continue
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "Longest Compound Word: " << longestCompoundWord << std::endl;
    std::cout << "Second Longest Compound Word: " << secondLongestCompoundWord << std::endl;
    std::cout << "Time taken to process file: " << duration << " milliseconds" << std::endl;

    return 0;
}

