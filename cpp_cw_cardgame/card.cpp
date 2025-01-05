#include <algorithm>
#include <random>
#include <iostream>
#include <iomanip>
#include "card.h"
#include "player.h"


std::string Card::getName() // returns name from any card given
{
    return name; 
}

void full_heal::Effect(Player* p) // heals user to 20 
{
    p->Health = 20;
}

void painful_lesson::Effect(Player* p) // deals 2 damage to enemy and forces them to draw a card
{
    p->Opponent->loseHealth(2);

    if (p->Opponent->canDrawCard()) {
        p->Opponent->drawCard();
    } else {
        std::cout << "\nOpponent has no card to draw";
    }
}

void spite::Effect(Player* p) // both players take 1 damage
{
    p->loseHealth(1);
    p->Opponent->loseHealth(1);
}

void peek::Effect(Player* p) // views both players top cards on their deck
{
    std::cout << "\nPlayers top card is: " << p->deck.back()->getName();
    std::cout << "\nComputers top card is: " << p->Opponent->deck.back()->getName() << std::endl;
}

void switcheroo::Effect(Player* p) // swaps the contents of their hands
{
    std::swap(p->hand, p->Opponent->hand);
}

void refresh::Effect(Player* p) // lose 3 health in return of getting cards from the discard pile back
{  
    p->loseHealth(3);

    std::random_device rd; // generates a seed
    std::mt19937 generator(rd()); // generates a random number based on a seed hence why rd is used as an argument
    std::shuffle(p->discard_pile.begin(), p->discard_pile.end(), generator); // function that shuffles the vector

    //add all contents of discard pile back into deck
    for(int i = 0; i < p->discard_pile.size(); i++) {
        p->deck.push_back(p->discard_pile.at(i));
        p->discard_pile.clear();
    }
}

