#include <string>
#include <sstream>

#include "hand.h"
#include "cards.h"


std::string Hand::to_string() const
{
    std::stringstream ss;

    ss << "Hand( ";

    for (const Card &card : cards)
    {
        ss << card << " ";
    }

    return ss.str();
}
std::wstring Hand::to_string_wide() const
{
    std::wstringstream ss;

    ss << L"Hand( ";

    for (const Card &card : cards)
    {
        ss << card << L" ";
    }

    ss << L")";

    return ss.str();
}

Hand Hand::get_random_hand(int n)
{
    Hand hand;
    hand.cards.reserve(n);

    for (size_t i = 0; i < n; i++)
    {
        hand.cards.push_back(Card::get_random_card());
    }

    return hand;
}

std::ostream &operator<<(std::ostream &os, const Hand &hand)
{
    os << hand.to_string();
    return os;
}

std::wostream &operator<<(std::wostream &os, const Hand &hand)
{
    os << hand.to_string_wide();
    return os;
}