#include "../include/puzzle.h"

#include <iostream>
#include <chrono>
#include <utility>
#include "../include/util.h"

Puzzle::Puzzle() {
    srand(time(0));
}

void Puzzle::generatePuzzle(int width, int lessClues) {
    // Setup puzzle board
    vector<vector<Cell>> board(width, std::vector<Cell>(width));
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {
            Cell c(j, i);
            board[j][i] = c;
        }
    }

    // Setup random black squares
    vector<pair<int, int>> wallsCoords;
    Cell current;
    current.isBlack = true;
    int wallsCount = 0;
    for (int i = 0; i < width + 2; i++) {
        // Choose a random cell that isn't already a wall
        int x = rand() % width;
        int y = rand() % width;
        while (current.isBlack) {
            current = board[x][y];
        }

        // Make the current cell a wall
        board[x][y].isBlack = true;
        board[x][y].isOpen = false;
        wallsCoords.push_back({x,y});

        // Make the 180 deg rotationally symmetric cell a wall
        int oppositeX = width - current.x - 1;
        int oppositeY = width - current.y - 1;
        board[oppositeX][oppositeY].isBlack = true;
        board[oppositeX][oppositeY].isOpen = false;
        wallsCoords.push_back({oppositeX, oppositeY});

        wallsCount+=2;
    }

    // Place random bulbs
    while (Util::countTotalOpenCells(board) > 0) {
        int newX = rand() % width;
        int newY = rand() % width;
        if (board[newX][newY].isOpen) {
            board = Util::placeBulb(board, newX, newY);
        }
    }

    // Pick random black cells to put a number on depending on neighboring bulbs
    for (int i = 0; i < (wallsCount / 2 - lessClues); i++) {
        pair<int, int> wallCoords = wallsCoords[rand() % wallsCoords.size()];
        board[wallCoords.first][wallCoords.second].num = Util::countNearbyBulbs(board, current.x, current.y);
    }

    // Remove bulbs
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            board[j][i].hasBulb = false;
        }
    }

    // Print puzzle's final state
    Util::printPuzzle(board);
}