#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void game(int target, int player_turn)
{
    int guess;
    cout << "Player " << player_turn << ", enter your guess (1-100): ";
    cin >> guess;

    if (guess == target)
    {
        cout << "Player " << player_turn << " wins! The correct number was " << target << "." << endl;
        return;
    }
    else if (guess < target)
    {
        cout << "Too low! Passing turn to next player." << endl;
    }
    else
    {
        cout << "Too high! Passing turn to next player." << endl;
    }
    int nextPlayer;
    if (player_turn == 1)
    {
        nextPlayer = 2;
    }
    else
    {
        nextPlayer = 1;
    }

    game(target, nextPlayer);
}
int main()
{
    srand(time(0));
    int target = rand() % 100 + 1;
    cout << "Number Guessing Game: " << endl;
    cout << "Players take turns guessing a number between 1 and 100." << endl;
    cout << "The one who guesses correctly wins!" << endl;
    game(target, 1);
    return 0;
}
