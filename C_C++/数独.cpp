/************************************
||    Author: Modest_xiaofeng      ||
||   Date: 2025-02-18 01:16:36     ||
|| Operating system: Ubuntu 24.04  ||
||         Editor: Vim             ||
||       QQ: 3198133420            ||
************************************/

#include <iostream>
using namespace std;

// 查找空格位置
bool findEmptyCell(int board[9][9], int &row, int &col) {
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

// 检查数字是否合法
bool isValid(int board[9][9], int row, int col, int num) {
    // 检查行
    for (int c = 0; c < 9; c++) {
        if (board[row][c] == num) return false;
    }
    // 检查列
    for (int r = 0; r < 9; r++) {
        if (board[r][col] == num) return false;
    }
    // 检查宫格
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (board[startRow + r][startCol + c] == num) {
                return false;
            }
        }
    }
    return true;
}

// 回溯求解函数
bool solveSudoku(int board[9][9]) {
    int row, col;
    if (!findEmptyCell(board, row, col)) {
        return true; // 数独已解
    }

    for (int num = 1; num <= 9; num++) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board)) {
                return true;
            }
            board[row][col] = 0; // 回溯
        }
    }
    return false;
}

// 打印数独棋盘
void printBoard(int board[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            cout << board[row][col] << " ";
            if (col == 2 || col == 5) {
                cout << "| ";
            }
        }
        cout << endl;
        if (row == 2 || row == 5) {
            cout << "---------------------" << endl;
        }
    }
}

int main() {
    // 示例数独（0表示空格）
    int board[9][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    if (solveSudoku(board)) {
        cout << "数独的解为：" << endl;
        printBoard(board);
    } else {
        cout << "该数独无解！" << endl;
    }

    return 0;
}
