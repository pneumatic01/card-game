#include <algorithm>
#include <random>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "player.h"
#include "card.h"



void Shuffle(std::vector<Card*> &cards)
{
    // initialising the whole deck
    cards = {
        new full_heal,
        new painful_lesson,
        new painful_lesson,
        new painful_lesson,
        new painful_lesson,
        new painful_lesson,
        new spite,
        new spite,
        new spite,
        new spite,
        new spite,
        new spite,
        new switcheroo,
        new switcheroo,
        new refresh,
        new refresh,
        new peek,
        new peek,
        new peek,
        new peek
    };

    std::random_device rd; // generates a seed
    std::mt19937 generator(rd()); // generates a random number based on a seed hence why rd is used as an argument
    std::shuffle(cards.begin(), cards.end(), generator); // shuffles it 

}


int main()
{
    // initializing below - creating objects + assinging values
    HumanPlayer* human = new HumanPlayer;
    ComputerPlayer* computer = new ComputerPlayer;

    human->Health = 20;
    computer->Health = 20;

    human->Opponent = computer;
    computer->Opponent = human;

    Shuffle(human->deck);
    Shuffle(computer->deck);


    while(!human->hasLost() || !computer->hasLost()) { // game loop 
        std::cout << "\nPlayers health: " << human->Health << '\n';
        human->myTurn();
        std::cout << "\n===========================\n"; // barriers for readability in game

        if(computer->hasLost()) // mid way check just to be sure
            break;

        std::cout << "Computers health: " << computer->Health << '\n';
        computer->myTurn();
        std::cout << "\n===========================\n";
    }

    if(human->hasLost())
        std::cout << "\nComputer wins!";
    else
        std::cout << "\nHuman wins!";
    

    return 0;
}

