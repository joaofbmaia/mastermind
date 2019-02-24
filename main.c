#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void validateGuess(void);
int black = 0;
int white = 0;
char code[5];
char guess[5];

int main(void) {
    srand(time(0));
    code[0] = rand() % 6 + '1';
    code[1] = rand() % 6 + '1';
    code[2] = rand() % 6 + '1';
    code[3] = rand() % 6 + '1';
    int turn = 0;
    printf("Mastermind attempt by Joao Maia\n");
    printf("4-digit code; digits 1-6\n");
//    printf("Code: %s\n", code);
    while(!(black == 4 && white == 0)){
        printf("\nGuess: ");
        scanf("%4s", guess);
        turn++;
        validateGuess();
        printf("Black: %d\nWhite: %d\n", black, white);
    }
    printf("Congratz! You guessed the code %s in %d turns.\n", code, turn);
    return(0);
}

void validateGuess(void) {
    //positions of whites and blacks
    int blacks[4] = {1, 1, 1, 1}; // 0 = peg in guess is same color as peg in code; 1 = peg in guess is different as peg in code
    int whites[4] = {1, 1, 1, 1}; // 0 = theres a peg in guess with same color as this peg on code; 1 = no pegs in guess with this color
    
    //check for blacks
    for(int i = 0; i<4; i++) {
        if(guess[i] == code[i]) blacks[i]=0; //mark black if match found
    }

    //check for whites
    for(int i = 0; i<4; i++) {
        if(blacks[i]) { //skip checking if theres already a black in this position (this position in the guess already matches code)
            for(int j = 0; j<4; j++) { //check against every position in code only if the pegs in code are not already marked with a black or white
                if((guess[i] == code[j]) && blacks[j] && whites[j]) {
                    whites[j] = 0; //mark white if theres a peg in guess with same color as this peg on code
                    break; //breaks for loop to avoid counting repeated whites in code (if theres a color more frequent in code than guess)
                }
            }
        }
    }

    //this sections counts the whites and blacks
    black = 0;
    white = 0;
    for(int i = 0; i<4; i++) {
        if(!blacks[i]) black++;
        if(!whites[i]) white++;
    }
}