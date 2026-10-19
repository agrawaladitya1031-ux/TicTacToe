
#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool checkWin(char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;

        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return true;
    }

    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;

    return false;
}

int main() {
    char player = 'X';
    int position;
    int moves = 0;

    cout << "===== TIC-TAC-TOE =====\n";
    cout << "Player X vs Player O\n";

    while (moves < 9) {
        displayBoard();

        cout << "Player " << player
             << ", choose a position (1-9): ";

        if (!(cin >> position)) {
            cout << "Invalid input. Enter a number.\n";
            return 0;
        }

        if (position < 1 || position > 9) {
            cout << "Choose a position from 1 to 9.\n";
            continue;
        }

        int row = (position - 1) / 3;
        int col = (position - 1) % 3;

        if (board[row][col] == 'X' ||
            board[row][col] == 'O') {
            cout << "That position is already occupied!\n";
            continue;
        }

        board[row][col] = player;
        moves++;

        if (checkWin(player)) {
            displayBoard();
            cout << "Player " << player << " wins!\n";
            return 0;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    displayBoard();
    cout << "It's a draw!\n";

    return 0;
}
