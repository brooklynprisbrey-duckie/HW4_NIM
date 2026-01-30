#include <iostream>
#include <random>

using namespace std;

bool isValidMove(int userMove, int stones) {//>3 and are there enough stones?
    if (0 < userMove && userMove <= 3) {
        if (userMove <= stones) { return 1; }
        cout << "Not enough stones in the pile for you to take!" << endl << 
            "Consider taking just " << stones << " from the pile?" << endl;
    }
    cout << userMove << " is an invalid amount. ";
    return 0;
}

int getUserMove(int stones) {
    int userMove = 0;
    do {
        cout << "Will you take 1, 2, or 3 stones from the pile?" << endl;
        while (!(cin >> userMove)) {
            cout << "How dare you not enter a number! The computer's trapped you in the writing void." << endl
                << "Write until the computer is satisfied." << endl;
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

int computerMove(int stones) {//computer will let you win
    if (stones == 1) { 
        cout << "The computer took " << stones << " stone." << endl;
        return stones; }
    else if (stones < 5) { 
        cout << "The computer took " << stones - 1 << " stones." << endl;
        return stones - 1; }
    else {
        default_random_engine seed;
        uniform_int_distribution<int> stoneTake(1, 3);
        int stoneTook;
        stoneTook = stoneTake(seed);
        cout << "The computer took " << stoneTook << " stones." << endl;
        return stoneTook;
    };
}

bool checkWin(int stones) {
    return stones;
}

int main() {
    int stonePile = 16;

    while (checkWin(stonePile)) {
        cout << "There are " << stonePile << " stones in the pile." << endl;
        stonePile -= getUserMove(stonePile);
        cout << "There are " << stonePile << " stones in the pile." << endl;
        if (!checkWin(stonePile)) { continue; }
        stonePile -= computerMove(stonePile);
    } 

    return 0;
}