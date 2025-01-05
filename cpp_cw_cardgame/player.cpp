#include <algorithm> // contains random useful functions
#include <random> // for generating random numbers + seeds
#include <iostream>
#include <vector>
#include <string>
#include "player.h"
#include "card.h"


int random(int min, int max) // generates a random number
{
    std::random_device rd; // generates a seed
    std::mt19937 gen(rd()); // generates a random number based on a seed hence why rd is used as an argument
    std::uniform_int_distribution<> random_choice(min, max); // sets a range between two values and only accepts integers
    return random_choice(gen);
}


void Player::drawCard() { // function to draw a card - this keyword refers to the current instantiated object
    this->hand.push_back(deck.back()); 
    this->deck.pop_back(); 
}


void Player::loseHealth(int i) { Health -= i; } // loses i amount of health

bool Player::canDrawCard() // returns true if player can draw a card
{
    if(deck.size() <= 0) { return false; }
    return true;
}

void Player::playCard(Card* c, int a) // i added the second parameter as a workaround - makes more sense below
{
    discard_pile.push_back(c);
    hand.erase(hand.begin() + a); // a is the index value
    c->Effect(this);
    std::cout << '\n' << c->getName() << " has been used!";
}


bool Player::hasLost() { return Health <= 0 || !canDrawCard(); } // return true if either health is 0 or below or if they cant draw a card


int DisplayAndPick(std::vector<Card*> &array) // for displaying the cards and picking the card with validation checks
{

    for(int i = 0 ; i < array.size(); i++) { // displays all current cards in hand
        std::cout << "\n[" << i << "] " << array.at(i)->getName(); 
    }

    std::cout << "\nPick a number to play the card / -1 to skip: ";
    int choice; std::cin >> choice;

    while(true) {
        while(std::cin.fail()){ //makes sure number is entered
            std::cin.clear(); // resets value of cin
            std::cin.ignore(INT_MAX, '\n'); // clears up invalid inputs, basically stops the infinite loop - int max is biggest num possible
            std::cout << "Invalid choice, retry: "; std::cin >> choice;
        }

        if(choice == -1 && array.size() < 6) // cant skip over 5 cards
            return choice;

        if(choice < array.size() && choice > -1) { //out of bounds check 
            return choice;
        }

        std::cout << "Invalid choice / cannot skip over 5 cards, retry: "; std::cin >> choice;
    }
}


void HumanPlayer::myTurn() // card picking and playing logic 
{


    //draw a card
    drawCard();

    while(true) {
        if(hand.empty()) { // skips if no cards in hand
            std::cout << "\nPlayer has no more cards to play\n";
            break;
        }

        int cardPicked = DisplayAndPick(hand);
        if(cardPicked == -1) { // -1 is to be able to skip
            std::cout << "\nPlayer's turn has ended\n";
            break;
        }

        Card* temp = hand.at(cardPicked); // store current card playing in a temp so i can delete it from the hand and then use it after
        playCard(temp, cardPicked); // card picked is sent so i can use its index value to erase the card from hand
    }
    

}

void ComputerPlayer::myTurn() // basically same as players but just generated a random number
{

    drawCard();

    while(true) {
        if(hand.empty()) {
            std::cout << "\nComputer has no more cards to play\n";
            break;
        }

        int cardPicked = random(-1 , hand.size() - 1); // random number generated to pick a card for the computer - hand size is taken by 1 because index starts from 0 
        if(cardPicked == -1) {
            std::cout << "\nComputer's turn has ended\n";
            break;
        }

        Card* temp = hand.at(cardPicked);
        playCard(temp, cardPicked);
    }

  

}