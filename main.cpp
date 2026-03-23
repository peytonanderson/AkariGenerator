/*
    This program randomly generates Akari puzzles.
    An explanation of the rules for Akari can be found at: https://www.nikoli.co.jp/en/puzzles/akari/
*/

#include <iostream>
#include "include/puzzle.h"

using namespace std;

int main() {
    Puzzle puzzle;
    
    // Accept user input to generate new Akari puzzle of specified difficulty and size
    cout << "Welcome to Akari Generator!" << endl;
    cout << "Press Ctrl+C at any time to exit." << endl << endl;
    while (true) {
        // Get puzzle size
        int size;
        cout << "Please enter a width for the puzzle (1-50): ";
        cin >> size;
        if (size < 1 || size > 50) {
            cout << "Size needs to be within 1 and 50." << endl << endl;
            continue;
        }
        
        // Get puzzle difficulty
        int difficulty;
        cout << "Please enter a difficulty level, from easy (1) to hard (3): ";
        cin >> difficulty;
        if (difficulty > 3 || difficulty < 1) {
            cout << "Difficulty needs to be within 1 and 3." << endl << endl;
            continue;
        }
        cout << endl;

        // Create puzzle
        puzzle.generatePuzzle(size, difficulty * 2);
    }
}