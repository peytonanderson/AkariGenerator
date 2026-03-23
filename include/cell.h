#pragma once

class Cell {
    public:
        Cell();

        Cell(int _x, int _y, bool _isBlack = false, int _num = -1);

        int num;
        bool isBlack;
        bool hasBulb;
        bool isOpen;
        int x;
        int y;
};