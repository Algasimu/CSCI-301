/**
 * problem description: this program about dictionary check. It reads a word in an inputed file from the user
 * and compares it with the saved disctionary and display the list of the misspelled words.
 * Name: Algassimou Diallo
 * startID: el8524jv
 * Instructor: Jie Meichsner
 * Due date: 07/11/2023
*/

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include "dictionaryBag.h"
using namespace std;




int main() {
    Dictionary dictionary;

    // Read words from the dictionary file and populate the dictionary Bag
    ifstream dictFile("/Volumes/academic/project4/dictionary.txt");
    if (!dictFile.is_open()) {
        cout << "Unable to open dictionary file." << endl;
        return 1;
    }

    string word;
    while (dictFile >> word) {
        dictionary.addWord(word);
    }
    dictFile.close();

    // // Prompt the user to enter the name of the file containing words to be checked
    //------------------------------------------------------------------------------------------

    cout << "Enter the path of the file that contains words to be checked: ";
    string filename;
    cin >> filename;
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cout << "Unable to open file: " << filename << endl;
        return 1;
    }

    string checkWord;
    unordered_set<string> misspelledWords;

    // Check each word from the input file against the dictionary
    while (inputFile >> checkWord) {
        if (!dictionary.contains(checkWord)) {
            misspelledWords.insert(checkWord);
        }
    }

    inputFile.close();

    if (misspelledWords.empty()) {
        cout << "No misspelled words found." << endl;
    } else {
        cout << "The following words in the file \"" << filename << "\" are not spelled correctly:" << endl;
        for (const string& misspelledWord : misspelledWords) {
            cout << misspelledWord << endl;
        }
    }

    cout << "Thanks for using the spell checker system." << endl;

    return 0;
}
