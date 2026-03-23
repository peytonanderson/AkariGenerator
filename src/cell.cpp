#include "../include/cell.h"

Cell::Cell() : num(-1), isBlack(false), hasBulb(false), isOpen(true) {}

Cell::Cell(int _x, int _y, bool _isBlack, int _num) {
    x = _x;
    y = _y;
    isBlack = _isBlack;
    num = _num;
    hasBulb = false;
    isOpen = !isBlack;
}