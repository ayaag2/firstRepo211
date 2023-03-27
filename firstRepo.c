// Program 1: TwentyFour Game
// Course: CS 211, Spring 2023, UIC
// System: Visual Studio Code for MacOS Monterey v12.4 and Replit
// Author: Adam Yaagoub with starter code provided by Ellen Kidane

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//This operation checker function calculates the value of sum, difference, product, or quotient of two integers based
// on the input operator. This function is only used for calculations for easy and hard mode, not debug mode.
//Input:
//  int num1: the first of two numbers to have operations done upon
//  int num2: the second of two numbers to have operations done upon
//  char op: the operator to be used
//Output:
//  returns an integer that is num1 +,-,*, or / num2
int opCheckerForGames(int num1, int num2, char op){
    int finalValue;
    if(op == '+'){
        finalValue = num1 + num2;
    }else if(op == '-'){
        finalValue = num1 - num2;
    }else if(op == '*'){
        finalValue = num1 * num2;
    }else if(op == '/'){
        finalValue = num1 / num2;
    }
    return finalValue;
}

//This operation checker function calculates the value of sum, difference, product, or quotient of two doubles based
// on the input operator. This function is only used for calculations for debug mode.
//Input:
//  double num1: the first of two numbers to have operations done upon
//  double num2: the second of two numbers to have operations done upon
//  char op: the operator to be used
//Output:
//  returns a double that is num1 +,-,*, or / num2
double opCheckerForDebug(double num1, double num2, char op){
    double finalValue;
    if(op == '+'){
        finalValue = num1 + num2;
    }else if(op == '-'){
        finalValue = num1 - num2;
    }else if(op == '*'){
        finalValue = num1 * num2;
    }else if(op == '/'){
        finalValue = num1 / num2;
    }
    return finalValue;
}

//The main function is where the loops that calculate the solutions and the loop that plays the game exist.
int main(int argc, char *argv[]) {
	srand(1);
    int easySolNums[10][4] = {{3, 9, 4, 1},{8, 5, 8, 1},{6, 1, 5, 1},{2, 8, 7, 8},{5, 2, 9, 2},{2, 6, 8, 4},{5, 5, 4, 3},{6, 6, 2, 6},{8, 4, 2, 6},{6, 2, 8, 1}};
    double sum1, sum2, sumFinal;
    char arr[] = {'+','-','*','/'};
    int numSolutions[3188][4];
    char opSolutions[3188][3];
    int cArrCurr = 0;

    //This block of nested for loops is how I calculate all possible combinations of 24 for the debug mode
    // and possible hard puzzles. The first 4 for loops loop through 1-9 to test all combinations of single digit
    // numbers. The next 3 loop over a char array of operators to test all types of calculation.
    int i, j, k, r, o, l, n;
    for(i = 1; i < 10; i++){
        for(j = 1; j < 10; j++){
            for(k = 1; k < 10; k++){
                for(r = 1; r < 10; r++){
                    //Operators
                    for(o = 0; o < 4; o++){
                        sum1 = opCheckerForDebug(i * 1.0, j * 1.0, arr[o]);
                        for(l = 0; l < 4; l++){
                            sum2 = opCheckerForDebug(sum1, k * 1.0, arr[l]);
                            for(n = 0; n < 4; n++){
                                sumFinal = opCheckerForDebug(sum2, r * 1.0, arr[n]);
                                if((sumFinal - 24.0) < 0.00000000001 && (sumFinal - 24.0) >= 0){
                                    //Assignment to the solutions arrays used to generate hard mode puzzles
                                    numSolutions[cArrCurr][0] = i;
                                    numSolutions[cArrCurr][1] = j;
                                    numSolutions[cArrCurr][2] = k;
                                    numSolutions[cArrCurr][3] = r;
                                    opSolutions[cArrCurr][0] = arr[o];
                                    opSolutions[cArrCurr][1] = arr[l];
                                    opSolutions[cArrCurr][2] = arr[n];
                                    cArrCurr++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    //Here is where argv and argc are used to get command line input. If -d or -e show up in the input,
    // we change debug and easy modes accordingly.
    int debug = 0;
    int easy = 1;
    for(int i = 0; i < argc; i++){
        if(argv[i][1] == 'd'){
            debug = atoi(argv[i+1]);
        }
        if(argv[i][1] == 'e'){
            easy = atoi(argv[i+1]);
        }
    }

    char userInput[10];
    int randNum;
    char inputString[100];
    int currVal;
    int m;
    int invalidChar = 0;
    printf("Welcome to the game of TwentyFour.\nUse each of the four numbers shown below exactly once,\ncombining them somehow with the basic mathematical operators (+,-,*,/)\nto yield the value twenty-four.\n\n");
    //All solutions printed out for debug mode
    if(debug == 1){
        for(int i = 0; i < 3188; i++){
            printf("%d. ", i + 1);
            for(int j = 0; j < 4; j++){
                printf("%d", numSolutions[i][j]);
                if(j < 3){
                    printf("%c", opSolutions[i][j]);
                }
            }
            printf("\n");
        }
    }
    //Main loop that continues playing the game, asking for input, and generating puzzles until the user enters
    // the exit key
    while(userInput[0] != 'N'){
        int invalidChar = 0;
        //Changes the calculation for the random puzzle based on which mode we are in due to the different
        // array sizes for the solutions for each.
        if(easy == 0){
            randNum = rand() % 3188;
          printf("The numbers to use are: %d, %d, %d, %d.\n", numSolutions[randNum][0],numSolutions[randNum][1],numSolutions[randNum][2],numSolutions[randNum][3]);
        }else{
            randNum = rand() % 10;
          printf("The numbers to use are: %d, %d, %d, %d.\n", easySolNums[randNum][0],easySolNums[randNum][1],easySolNums[randNum][2],easySolNums[randNum][3]);
        }
        printf("Enter the three operators to be used, in order (+,-,*, or /): ");
        scanf("%s", &inputString);
        //This block ensures valid operators
        for(m = 0; m < 3; m++){
            if(inputString[3] != NULL || !(inputString[2] != NULL) || !(inputString[1] != NULL) || !(inputString[0] != NULL)){
                printf("Error! The number of operators is incorrect. Please try again.\n\n");
                invalidChar = 1;
                break;
            }
            if(inputString[m] != '*' && inputString[m] != '/' && inputString[m] != '+' && inputString[m] != '-' ){
                printf("Error! Invalid operator entered. Please try again.\n\n");
                invalidChar = 1;
                break;
            }
        }
        //Restarts the loop if input was invalid 
        if(invalidChar == 1){
            continue;
        }
        //Game on hard mode
        if(easy == 0){
            printf("%d %c %d = ", numSolutions[randNum][0], inputString[0], numSolutions[randNum][1]);
            currVal = opCheckerForGames(numSolutions[randNum][0], numSolutions[randNum][1], inputString[0]);
            printf("%d.\n", currVal);
            printf("%d %c %d = ", currVal, inputString[1], numSolutions[randNum][2]);
            currVal = opCheckerForGames(currVal, numSolutions[randNum][2], inputString[1]);
            printf("%d.\n", currVal);
            printf("%d %c %d = ", currVal, inputString[2], numSolutions[randNum][3]);
            currVal = opCheckerForGames(currVal, numSolutions[randNum][3], inputString[2]);
            printf("%d.\n", currVal);
            if(currVal == 24 || (inputString[0] == opSolutions[randNum][0] && inputString[1] == opSolutions[randNum][1] && inputString[2] == opSolutions[randNum][2])){
                printf("Well done! You are a math genius.\n\n");
            }else{
                printf("Sorry. Your solution did not evaluate to 24.\n\n");
            }
            printf("Would you like to play again? Enter N for no and any other character for yes. ");
            scanf(" %s", &userInput);
            printf("\n");
        //Game on easy mode
        }else if(easy == 1){
            printf("%d %c %d = ", easySolNums[randNum][0], inputString[0], easySolNums[randNum][1]);
            currVal = opCheckerForGames(easySolNums[randNum][0], easySolNums[randNum][1], inputString[0]);
            printf("%d.\n", currVal);
            printf("%d %c %d = ", currVal, inputString[1], easySolNums[randNum][2]);
            currVal = opCheckerForGames(currVal, easySolNums[randNum][2], inputString[1]);
            printf("%d.\n", currVal);
            printf("%d %c %d = ", currVal, inputString[2], easySolNums[randNum][3]);
            currVal = opCheckerForGames(currVal, easySolNums[randNum][3], inputString[2]);
            printf("%d.\n", currVal);
            if(currVal == 24){
                printf("Well done! You are a math genius.\n\n");
            }else{
                printf("Sorry. Your solution did not evaluate to 24.\n\n");
            }
            printf("Would you like to play again? Enter N for no and any other character for yes. ");
            scanf(" %s", &userInput);
            printf("\n");
        }
    }
    printf("Thanks for playing!");

	return 0;
}
