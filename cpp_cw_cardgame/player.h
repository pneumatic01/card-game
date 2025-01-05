#ifndef PLAYER_H // header guards to avoid copies when including namespaces
#define PLAYER_H

#include <vector>

class Card; // pre defined so i can access

class Player // player base class 
{
    public:
        int Health;
        Player* Opponent;
        std::vector<Card*> deck, hand, discard_pile;
        //methods below
        void loseHealth(int i);
        bool canDrawCard();
        void drawCard();
        void playCard(Card* c, int a); 
        virtual void myTurn() = 0;
        bool hasLost();
};

//abstract classes below

class HumanPlayer : public Player
{
    public:
        void myTurn() override;
};

class ComputerPlayer : public Player
{
    public:
        void myTurn() override;
};

#endif