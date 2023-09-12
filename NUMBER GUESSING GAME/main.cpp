#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
  srand(static_cast<unsigned int>(time(nullptr)));

  int secretNumber;
  int player1Guess, player2Guess;
  int currentPlayer = 1;
  bool player1Wins = false, player2Wins = false;

  secretNumber = rand() % 100 + 1;

  cout << "Welcome to the Number Guessing Game!" << endl;

  while (!player1Wins && !player2Wins) {
    cout << "Player " << currentPlayer << ", enter your guess: ";
    cin >> (currentPlayer == 1 ? player1Guess : player2Guess);

    if (currentPlayer == 1) {
      if (player1Guess == secretNumber) {
        player1Wins = true;
      } else if (player1Guess < secretNumber) {
        cout << "Player 1: Too low! Try again." << endl;
      } else {
        cout << "Player 1: Too high! Try again." << endl;
      }
    } else {
      if (player2Guess == secretNumber) {
        player2Wins = true;
      } else if (player2Guess < secretNumber) {
        cout << "Player 2: Too low! Try again." << endl;
      } else {
        cout << "Player 2: Too high! Try again." << endl;
      }
    }

    currentPlayer = (currentPlayer == 1) ? 2 : 1;
  }

  if (player1Wins) {
    cout << "Player 1 wins! The secret number was " << secretNumber << endl;
  } else {
    cout << "Player 2 wins! The secret number was " << secretNumber << endl;
  }

  return 0;
}
