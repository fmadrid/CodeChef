#include<iostream>
#include<fstream>
#include<set>
#include<vector>

#define DEBUG true

using std::vector;
using std::string;
using std::set;

// Stores read words from a dictionary file into a 2d array:
//  0 -> {""}
//  1 -> {"a", "b", "c", ...}
//  2 -> {"at", "an", ... }
vector<vector<string>> parseWordList(std::string filename) {

    vector<vector<string>> dictionary;
    std::ifstream fin(filename);

    std::string word;
    while(fin >> word) {

        // If we haven't seen a word of at least length n, resize dictionary to n + 1
        if(word.length() >= dictionary.size()) dictionary.resize(word.length() + 1);
        dictionary[word.length()].push_back(word);

    }

    fin.close();

    return dictionary;
}

// Outputs the number of words of each count 
void printStatistics(vector<vector<string>>& wordMap) {

    int totalWords = 0;
    std::cout << "Dictionary Statistics: \n";
    for(int i = 0; i < wordMap.size(); i++) {
        std::cout << "\tLength: " << i << " Count: " << wordMap[i].size() << "\n";
        totalWords += wordMap[i].size();
    }
    std::cout << "Total Count: " << totalWords << "\n";

}

// For each decomposable word dWords, insert each character into each possible position and see if the word exists, if
// so add it to a unique set
std::set<string> findDecomposedWords(const std::set<string>& oldDWords, const std::set<string>& candidateWords) {

    std::set<string> newDWords;
    for(auto it = oldDWords.begin(); it!= oldDWords.end(); it++) {
        for(int i = 0; i <= it->length(); i++) {
            for(int j = 0; j < 26; j++) {
                string temp = *it;
                temp.insert(temp.begin() + i, (char) ('a' + j));
                if(candidateWords.find(temp) != candidateWords.end())
                    newDWords.insert(temp);
            }
        }

    }

    return newDWords;

}

/* Utility Functions */
template<typename T>
void printVector(const vector<T> v) {
    for(T t : v)
        std::cout << t << "\n";
}

template<typename T>
void printSet(const std::set<T> s) {
    for(auto it = s.begin(); it != s.end(); it++)
        std::cout << *it << "\n";
}

int main(int argc, char** argv) {

    if(argc < 2) {
        std::cout << "Usage: ./a.exe <DictionaryFile>\n";
        return 1;
    }

    vector<vector<string>> dictionary = parseWordList(argv[1]);

    if(DEBUG) printStatistics(dictionary);

    // List of decomposable words
    vector<string> dWords;

    // Decomposable words of a given size i
    std::set<string> tempDWords;
    tempDWords.insert("");

    for(int i = 1; i <= dictionary.size(); i++) {

        if(dictionary[i].empty()) break;

        // Binary search tree of words of length i
        std::set<string> candidateWords;
        for(string str: dictionary[i]) candidateWords.insert(str);

        // Get decomposable words of length i
        if(!candidateWords.empty()) tempDWords = findDecomposedWords(tempDWords, candidateWords);

        // Found no new decomposable words
        if(tempDWords.empty()) break;

        if(DEBUG) std::cout << "Length: " << i << " Count: " << tempDWords.size() << "\n";
        for(auto it = tempDWords.begin(); it != tempDWords.end(); it++)
            dWords.push_back(*it);
    }

    // Print decomposable words to output file
    std::cout << "DecomposedWords.txt";
    for(string str: dWords)
        std::cout << str << "\n";

    return 0;

}



