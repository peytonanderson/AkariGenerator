#include "../include/util.h"

#include <iostream>

// Place a bulb on the given cell and light up the available cells in each direction
vector<vector<Cell>> Util::placeBulb(vector<vector<Cell>> board, int x, int y) {
    // Place the bulb
    board[x][y].hasBulb = true;
    board[x][y].isOpen = false;

    // Clear the bulb's row and column up to a black square or edge
    if (y-1 > -1) {
        int newY = y-1;
        while (newY > -1 && !board[x][newY].isBlack) {
            board[x][newY].isOpen = false;
            newY--;
        }
    }
    if (y+1 < board.size()) {
        int newY = y+1;
        while (newY < board.size() && !board[x][newY].isBlack) {
            board[x][newY].isOpen = false;
            newY++;
        }
    }
    if (x-1 > -1) {
        int newX = x-1;
        while (newX > -1 && !board[newX][y].isBlack) {
            board[newX][y].isOpen = false;
            newX--;
        }
    }
    if (x+1 < board.size()) {
        int newX = x+1;
        while (newX < board.size() && !board[newX][y].isBlack) {
            board[newX][y].isOpen = false;
            newX++;
        }
    }

    return board;
}

// Count every bulb around the given cell
int Util::countNearbyBulbs(vector<vector<Cell>> board, int x, int y) {
    int count = 0; 

    // Search each cardinal direction
    if (y-1 > -1 && board[x][y-1].hasBulb) {
        count++;
    }
    if (y+1 < board.size() && board[x][y].hasBulb) {
        count++;
    }
    if (x-1 > -1 && board[x-1][y].hasBulb) {
        count++;
    }
    if (x+1 < board.size() && board[x+1][y].hasBulb) {
        count++;
    }

    return count;
}

// Count every white cell without a bulb
int Util::countTotalOpenCells(vector<vector<Cell>> board) {
    int count = 0;

    for (int i = 0; i < board[0].size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[j][i].isOpen) {
                count++;
            }
        }
    }

    return count;
}

// Print out a representation of the puzzle
void Util::printPuzzle(vector<vector<Cell>> board) {
    for (int i = 0; i < board[0].size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[j][i].num > -1) {
                cout << board[j][i].num;
            } else if (board[j][i].isBlack) {
                cout << "B";
            } else {
                cout << "W";
            }

            if (board[j][i].hasBulb) {
                cout << "O ";
            } else {
                cout << "X ";
            }
        }

        cout << endl;
    }
    
    cout << endl;
}