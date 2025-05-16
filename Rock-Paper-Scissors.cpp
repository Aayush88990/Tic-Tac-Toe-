#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to get computer's choice
string getComputerChoice() {
    string choices[3] = {"rock", "paper", "scissors"};
    int randomIndex = rand() % 3;
    return choices[randomIndex];
}

// Function to decide winner
string getWinner(string player, string computer) {
    if (player == computer) return "It's a draw!";
    if ((player == "rock" && computer == "scissors") ||
        (player == "paper" && computer == "rock") ||
        (player == "scissors" && computer == "paper")) {
        return "You win!";
    }
    return "Computer wins!";
}

int main() {
    srand(time(0)); // seed for random number generator

    string playerChoice;
    cout << "Welcome to Rock-Paper-Scissors!" << endl;
    cout << "Enter your choice (rock, paper, scissors): ";
    cin >> playerChoice;

    // Convert to lowercase for consistent comparison
    for (auto &c : playerChoice) c = tolower(c);

    // Validate input
    if (playerChoice != "rock" && playerChoice != "paper" && playerChoice != "scissors") {
        cout << "Invalid choice! Please choose rock, paper, or scissors." << endl;
        return 1;
    }

    string computerChoice = getComputerChoice();
    cout << "Computer chose: " << computerChoice << endl;

    string result = getWinner(playerChoice, computerChoice);
    cout << result << endl;

    return 0;
}