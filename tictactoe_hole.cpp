#include <iostream>

using namespace std;

char board[3][3] = ...;

void drawBoard() {
    cout << "-------------" << endl;
    for(int i = 0; i < 3; ++i) {
        cout << "| ";
        for(int j = 0; j < 3; ++j) {
            cout << ... << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

bool checkWin() {
    for(int i = 0; i < 3; ++i) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if(...)
            return true;
    }
    if(...)
        return true;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;
    return false;
}

bool checkDraw() {
    for(...) {
        for(...) {
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

int main() {
    int player = 1;
    char mark;
    bool gameOver = false;

    do {
        drawBoard();
        player = (player % 2) ? 1 : 2;
        cout << "Player " << player << ", enter a number: ";
        int choice;
        cin >> choice;
        mark = (player == 1) ? 'X' : 'O';

        switch(choice) {
            case 1: if(board[0][0] == '1') board[0][0] = mark; break;
            case 2: if(board[0][1] == '2') board[0][1] = mark; break;
            case 3: if(board[0][2] == '3')     ...     = mark; break;
            case 4: if(       ...        ) board[1][0] = mark; break;
            case 5: if(       ...        )     ...     = mark; break;
            case 6: if(       ...        )     ...     = mark; break;
            case 7: if(       ...        )     ...     = mark; break;
            case 8: if(       ...        )     ...     = mark; break;
            case 9: if(       ...        )     ...     = mark; break;
            default: cout << "Invalid move!" << endl;
        }

        if(checkWin()) {
            drawBoard();
            cout << "Player " << player << " wins!" << endl;
            gameOver = ...;
        } else if(checkDraw()) {
            drawBoard();
            cout << "It's a draw!" << endl;
            gameOver = ...;
        }
        player++;
    } while(!gameOver);

    return 0;
}
