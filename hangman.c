#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printboard(int moves) {
    switch (moves) {
        case 0: 
            printf("-----------\n"); 
            break;
        case 1:
            printf("     |     \n");
            printf("     |     \n");
            printf("     |     \n");
            printf("     |     \n");
            printboard(0);
            break;
        case 2:
            printf("     ------\n");
            printboard(1);
            break;
        case 3:
            printf("     ------\n");
            printf("     |    |\n");
            printf("     |    0\n");
            printf("     |     \n");
            printf("     |     \n");
            printboard(0);
            break;
        case 4:
            printf("     ------\n");
            printf("     |    |\n");
            printf("     |    0\n");
            printf("     |    |\n");
            printf("     |     \n");
            printboard(0);
            break;
        case 5:
            printf("     ------\n");
            printf("     |    |\n");
            printf("     |    0\n");
            printf("     |    |\n");
            printf("     |   / \n");
            printboard(0);
            break;
        case 6:
            printf("     ------\n");
            printf("     |    |\n");
            printf("     |    0\n");
            printf("     |    |\n");
            printf("     |   / \\\n");
            printboard(0);
            break;
        case 7:
            printf("     ------\n");
            printf("     |    |\n");
            printf("     |    0\n");
            printf("     |    |\n");
            printf("     |   / \\\n");
            printboard(0);
            break;
        case 8:
            printf("     ------\n");
            printf("     |    |\n");
            printf("     |    0\n");
            printf("     |   /|\n");
            printf("     |   / \\\n");
            printboard(0);
            break;
        case 9:
            printf("     ------\n");
            printf("     |    |\n");
            printf("     |    0\n");
            printf("     |   /|\\\n");
            printf("     |   / \\\n");
            printboard(0);
            break;
    }       
}

int main() {
    // https://www.randomlists.com/nouns
    char *words[] = {
        "flight",
        "guitar",
        "education",
        "comparison",
        "calculator",
        "pancake",
        "furniture",
        "digestion",
        "competition"
    };

    int index = rand() % (sizeof(*words)) + 1;
    int wordlen = strlen(words[index]);
    char word[wordlen];
    strcpy(word, words[index]);

    int wrong = 0;
    char guess[wordlen];
    char input;
    int correct;

    for (int i = 0; i < wordlen; i++) {
        guess[i] = '_';
    }

    while (wrong < 9) {
        printboard(wrong);

        printf("\n");
        for (int i = 0; i < wordlen; i++) {
            printf("%c ", guess[i]);
        }
        printf("\n");
        printf("Letter would you like to guess?");
        scanf("%c", &input);

        correct = 0;

        for (int i = 0; i < wordlen; i++) {
            if (word[i] == input) {
                guess[i] = input;
                correct = 1;
            }
        }

        if (correct == 0) {
            wrong++;
        }
    }

    printboard(9);
    printf("you lost!");
    return 0;
}