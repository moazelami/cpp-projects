#include <iostream>
#include <cstdlib>
using namespace std;

const int WIDTH = 10;
const int HEIGHT = 5;

void resetBoard(char board[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            board[i][j] = '.';
}

void printBoard(char board[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

void movePlayer(int& x, int& y, char move) {
    if (move == 'w' || move == 'W') y--;
    else if (move == 's' || move == 'S') y++;
    else if (move == 'a' || move == 'A') x--;
    else if (move == 'd' || move == 'D') x++;

    x = (x + WIDTH) % WIDTH;
    y = (y + HEIGHT) % HEIGHT;
}

bool checkCollision(int px, int py, int ox, int oy) {
    return (px == ox && py == oy);
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    char board[HEIGHT][WIDTH];

    int playerX = 0, playerY = 0;
    int obstacleX = 4, obstacleY = 2;

    char move;

    while (true) {
        clearScreen();

        resetBoard(board);
        board[playerY][playerX] = '@';
        board[obstacleY][obstacleX] = 'X';

        printBoard(board);
        cout << "Move (W/A/S/D) or Q to quit: ";
        cin >> move;

        if (move == 'q' || move == 'Q') {
            cout << "You quit the game." << endl;
            break;
        }

        movePlayer(playerX, playerY, move);

        if (checkCollision(playerX, playerY, obstacleX, obstacleY)) {
            clearScreen();
            resetBoard(board);
            board[playerY][playerX] = '@';
            printBoard(board);
            cout << "Game Over!" << endl;
            break;
        }
    }

    return 0;
}
