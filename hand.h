#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <map>
#include <string>
#include <string>
#include <vector>
#include <algorithm>

#include "cards.h"

class Hand
{

    static Hand find_straight(Hand hand);

public:
    Hand() = default;
    explicit Hand(std::vector<Card> cards) : cards(cards)
    {
        std::sort(cards.begin(), cards.end());
    };
    std::vector<Card> cards;
    Hand find_best_hand();
    Hand get_subhand(Card::Suit suit);
    Hand get_subhand(Card::Rank rank);

    static Hand get_random_hand(int n = 8);

    std::string to_string() const;
    std::wstring to_string_wide() const;
};

std::ostream &operator<<(std::ostream &os, const Hand &hand);
std::wostream &operator<<(std::wostream &os, const Hand &hand);

#endif