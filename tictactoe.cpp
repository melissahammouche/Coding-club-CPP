#include <iostream>

using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void drawBoard() {
    cout << "-------------" << endl;
    for(int i = 0; i < 3; ++i) {
        cout << "| ";
        for(int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

bool checkWin() {
    for(int i = 0; i < 3; ++i) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;
    return false;
}

bool checkDraw() {
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
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
            case 3: if(board[0][2] == '3') board[0][2] = mark; break;
            case 4: if(board[1][0] == '4') board[1][0] = mark; break;
            case 5: if(board[1][1] == '5') board[1][1] = mark; break;
            case 6: if(board[1][2] == '6') board[1][2] = mark; break;
            case 7: if(board[2][0] == '7') board[2][0] = mark; break;
            case 8: if(board[2][1] == '8') board[2][1] = mark; break;
            case 9: if(board[2][2] == '9') board[2][2] = mark; break;
            default: cout << "Invalid move!" << endl;
        }

        if(checkWin()) {
            drawBoard();
            cout << "Player " << player << " wins!" << endl;
            gameOver = true;
        } else if(checkDraw()) {
            drawBoard();
            cout << "It's a draw!" << endl;
            gameOver = true;
        }

        player++;
    } while(!gameOver);

    return 0;
}
