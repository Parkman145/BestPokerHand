#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include <map>
#include <string>
#include <string>
#include <vector>
#include <algorithm>

struct Card
{
public:
    enum Rank
    {
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING,
        ACE
    };
    enum Suit
    {
        HEARTS,
        DIAMONDS,
        SPADES,
        CLUBS
    };

    Card(Rank rank, Suit suit);

    bool operator==(const Card other);
    bool operator<(const Card other);

    static Card get_random_card();

    Rank rank;
    Suit suit;

    friend Card operator""_card(const char *str, std::size_t n);

private:
    inline static const std::map<std::string, Rank> rank_map = {
        {"2", TWO},
        {"3", THREE},
        {"4", FOUR},
        {"5", FIVE},
        {"6", SIX},
        {"7", SEVEN},
        {"8", EIGHT},
        {"9", NINE},
        {"10", TEN},
        {"J", JACK},
        {"Q", QUEEN},
        {"K", KING},
        {"A", ACE}};

    inline static const std::map<std::string, Suit> suit_map = {
        {"H", HEARTS},
        {"D", DIAMONDS},
        {"S", SPADES},
        {"C", CLUBS}};
};

std::ostream &operator<<(std::ostream &os, const Card &card);
std::wostream &operator<<(std::wostream &os, const Card &card);

Card operator""_card(const char *str, std::size_t n);

#endif