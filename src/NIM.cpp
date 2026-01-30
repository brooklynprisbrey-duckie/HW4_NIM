#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
//TODO: Create a function named isValidMove(). It needs to have boolean return type
//      and it needs to take two parameters: int userMove and int stones.
//      This function is to determine if the move is valid or not. If the user move
//      is less than 1, greater than 3, or if their move is greater than the number
//      of available stones, then return false. Else return true.
bool isValidMove(int userMove, int stones) {//>3 and are there enough stones?
    if (userMove <= 4 && 0 < userMove) {
        if (userMove <= stones)
        {return 1;}
        cout << "Not enough stones in the pile for you to take!";
    }
    return 0;
}
//TODO: Create a function named getUserMove(). It needs to have a int return type and
//      it needs to take one parameter: int stones.
//      The purpose of the function is to get the users move. You will need to
//      do the following steps in the function:
//      1) create a a loop that will only break when a valid move is made
//      2) inside the loop ask the user how many stones they would like to take and
//         then have them input their answer
//      3) if the move is valid, return the user's move. Else print "Invalid amount."
//         (hint: use the isValidMove function to test if the move is valid)
int getUserMove(int stones) {
    int userMove = 0;
    do {
        cout << "Will you take 1, 2, or 3 stones from the pile?" << endl;
        while (!(cin >> userMove)) {
            cout << "How dare you not enter a number! I've trapped you in the writing void." << endl
                << "Write until I am satisfied." << endl;
            cin.clear();
            cin.ignore(50);//writing void, prevents creation of writing vortex.
            cout << "Enough! Your writing is satisfactory.";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');//escape writing void when newline, clears writing out.
            cout << "Got to be an integer! Try 100." << endl;
        }
    } while (!isValidMove(userMove, stones));
    return userMove;
}
//TODO: Create a function named computerMove() that has a return type of int. It needs
//      to take one parameter: int stones.
//      The purpose of this function is to program how many stones the computer will
//      take on their move.
//      If the number of stones = 1 or 2 then return 1. If stones = 3 then return 2.
//      If stones = 4 then return 3. Else return a random number between 1 and 3.
int computerMove(int stones) {//computer will let you win
    return 1;
}
//TODO: Create a function of type bool named checkWin(). It will take one parameter: int stones
//      This one should be very simple, if there are no stones left then return true else 
//      return false.
bool checkWin(int stones) {
    return stones;
}

int main() {
    //TODO: Start the stone count at 16 and tell the user how many stones are in the 
    //      pile
    int stonePile = 16;
    srand(time(0));
    //TODO: Create a loop that will only break when the game is over.
    //      Within the loop, have the user take their move then subtract
    //      the result of the user's move with the total number of stones.
    do {
        cout << "There are " << stonePile << " stones in the pile." << endl;
        stonePile -= getUserMove(stonePile);
    } while (checkWin(stonePile));
    //TODO: Once again print how many stones are remaining and then check the
    //      the win condition.

    //TODO: Now have the computer take its turn. Subtract the computer's move
    //      from the total number of stones.

    //TODO: Print the total number of stones and then check the win condition

    return 0;
}