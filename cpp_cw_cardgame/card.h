#ifndef CARD_H // header guards to avoid copies when including namespaces
#define CARD_H

#include <string>

class Player; //pre defined so i can access

class Card
{
    protected: // only accessible to classes that derive from this one
        std::string name;
    public:
        std::string getName(); // doesnt need to be virtual, i am not going to redefine getName for every single card
        virtual void Effect(Player* p) = 0;
};

// below are just class definitons

class full_heal : public Card
{
    public:
        full_heal() { name = "Full Heal"; }
        void Effect(Player* p) override;
};

class painful_lesson : public Card
{
    public:
        painful_lesson() { name = "Painful Lesson"; }
        void Effect(Player* p) override;
};

class spite : public Card
{
    public:
        spite() { name = "Spite"; }
        void Effect(Player* p) override;
};

class switcheroo : public Card
{
    public:
        switcheroo() { name = "Switcheroo"; }
        void Effect(Player* p) override;
};

class refresh : public Card
{
    public:
        refresh() { name = "Refresh"; }
        void Effect(Player* p) override;
};

class peek : public Card
{
    public:
        peek() { name = "Peek"; }
        void Effect(Player* p) override;
};



#endif