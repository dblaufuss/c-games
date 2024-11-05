#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("rock (1), paper (2), or scissors (3)?\n");
    int input;
    scanf("%d", &input);

    int computer = rand() % 3 + 1;

    switch (input) {
        case 1:
            switch (computer) {
                case 1: printf("computer chose rock. tie!"); break;
                case 2: printf("computer chose paper. you lose!"); break;
                case 3: printf("computer chose scissors. you win!"); break;
            }
            break;
        case 2: 
            switch (computer) {
                case 1: printf("computer chose rock. you win!"); break;
                case 2: printf("computer chose paper. tie!"); break;
                case 3: printf("computer chose scissors. you lose!"); break;
            }
            break;
        case 3:
            switch (computer) {
                case 1: printf("computer chose rock. you lose!"); break;
                case 2: printf("computer chose paper. you win!"); break;
                case 3: printf("computer chose scissors. tie!"); break;
            }
            break;
        default: 
            printf("invalid input");
            break;
    }
    return 0;
}