#include <stdio.h>
#include <stdlib.h>

void printboard(int b[3][3]) {
    for (int i = 0; i < 3; i++) {
        printf("-------------\n");
        for (int j = 0; j < 3; j++) {
            switch (b[i][j]) {
                case 0: printf("|   "); break;
                case 1: printf("| x "); break;
                case 2: printf("| 0 "); break;
            }
        }
        printf("|");
        printf("\n");
    }
    printf("-------------\n");
}

int checkwin(int b[3][3]) {
    for (int i = 0; i < 3; i++) {
        // horizontal
        if (b[i][0] != 0 && b[i][0] == b[i][1] && b[i][1] == b[i][2]) {
            return b[i][0];
        }

        // vertical
        if (b[0][i] != 0 && b[0][i] == b[1][i] && b[1][i] == b[2][i]) {
            return b[0][i];
        }
    }

    // diagonal
    if (b[0][0] != 0 && b[0][0] == b[1][1] && b[1][1] == b[2][2]) {
        return b[0][0];
    }
    
    if (b[2][0] != 0 && b[2][0] == b[1][1] && b[1][1] == b[0][2]) {
        return b[0][0];
    }

    // check for tie
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (b[i][j] != b[0][0]) {
                return 0;
            }
        }
    }
    return 3;
}

int main() {
    int board[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    int row;
    int col;

    int cpurow;
    int cpucol;

    printf("you are x, computer is o\n");
    printboard(board);

    while (1) {
        // take user input
        printf("where would you like to play?\n");
        
        printf("row: ");
        scanf("%d", &row);

        printf("col: ");
        scanf("%d", &col);

        if (row > 2 || col > 2 || row < 0 || col < 0 || board[row][col] != 0) {
            printf("you can't play there!\n");
            continue;
        }
        board[row][col] = 1;

        switch (checkwin(board)) {
            case 1: printboard(board); printf("you win!"); return 0;
            case 2: printboard(board); printf("you lose!"); return 0;
            case 3: printboard(board); printf("tie!"); return 0;
        }

        // create random cpu move
        cpurow = rand() % 3;
        cpucol = rand() % 3;

        while (board[cpurow][cpucol] != 0) {
            cpurow = rand() % 3;
            cpucol = rand() % 3;
        }

        board[cpurow][cpucol] = 2;
        
        switch (checkwin(board)) {
            case 1: printboard(board); printf("you win!"); return 0;
            case 2: printboard(board); printf("you lose!"); return 0;
            case 3: printboard(board); printf("tie!"); return 0;
        }

        printboard(board);
    }
}