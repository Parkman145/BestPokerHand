#include <random>
#include <sstream>

#include "cards.h"

Card::Card(Card::Rank rank, Card::Suit suit) : rank(rank), suit(suit) {}

Card Card::get_random_card()
{
    return Card(Card::Rank(rand() % 13), Card::Suit(rand() % 4));
}

std::string Card::to_string() const
{
    std::stringstream ss;

    switch (rank)
    {
    case Card::Rank::TWO:
        ss << "2";
        break;
    case Card::Rank::THREE:
        ss << "3";
        break;
    case Card::Rank::FOUR:
        ss << "4";
        break;
    case Card::Rank::FIVE:
        ss << "5";
        break;
    case Card::Rank::SIX:
        ss << "6";
        break;
    case Card::Rank::SEVEN:
        ss << "7";
        break;
    case Card::Rank::EIGHT:
        ss << "8";
        break;
    case Card::Rank::NINE:
        ss << "9";
        break;
    case Card::Rank::TEN:
        ss << "10";
        break;
    case Card::Rank::JACK:
        ss << "J";
        break;
    case Card::Rank::QUEEN:
        ss << "Q";
        break;
    case Card::Rank::KING:
        ss << "K";
        break;
    case Card::Rank::ACE:
        ss << "A";
        break;
    default:
        ss << "?";
        break;
    }
    switch (suit)
    {
    case Card::HEARTS:
        ss << "H";
        break;
    case Card::DIAMONDS:
        ss << "D";
        break;
    case Card::SPADES:
        ss << "S";
        break;
    case Card::CLUBS:
        ss << "C";
        break;
    default:
        ss << "?";
    }

    return ss.str();
}

std::wstring Card::to_string_wide() const
{
    std::wstringstream ss;

    switch (rank)
    {
    case Card::Rank::TWO:
        ss << L"2";
        break;
    case Card::Rank::THREE:
        ss << L"3";
        break;
    case Card::Rank::FOUR:
        ss << L"4";
        break;
    case Card::Rank::FIVE:
        ss << L"5";
        break;
    case Card::Rank::SIX:
        ss << L"6";
        break;
    case Card::Rank::SEVEN:
        ss << L"7";
        break;
    case Card::Rank::EIGHT:
        ss << L"8";
        break;
    case Card::Rank::NINE:
        ss << L"9";
        break;
    case Card::Rank::TEN:
        ss << L"10";
        break;
    case Card::Rank::JACK:
        ss << L"J";
        break;
    case Card::Rank::QUEEN:
        ss << L"Q";
        break;
    case Card::Rank::KING:
        ss << L"K";
        break;
    case Card::Rank::ACE:
        ss << L"A";
        break;
    default:
        ss << L"?";
        break;
    }
    switch (suit)
    {
    case Card::HEARTS:
        ss << L"♥";
        break;
    case Card::DIAMONDS:
        ss << L"♦";
        break;
    case Card::SPADES:
        ss << L"♠";
        break;
    case Card::CLUBS:
        ss << L"♣";
        break;
    default:
        ss << L"?";
    }

    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Card &card)
{
    os << card.to_string();
    return os;
}

std::wostream &operator<<(std::wostream &os, const Card &card)
{
    os << card.to_string_wide();
    return os;
}

bool Card::operator==(const Card other) { return rank == other.rank && suit == other.suit; }
bool Card::operator<(const Card other) { return rank < other.rank; }

Card operator""_card(const char *str, std::size_t n)
{
    // What the fuck
    // Never let bro cook again
    // No verification, who cares tbh
    // Maybe I'll implement static checking in the future
    Card::Rank rank;
    Card::Suit suit;

    if (n == 2)
    {
        rank = Card::rank_map.at(std::string(1, str[0]));
        suit = Card::suit_map.at(std::string(1, str[1]));
    }
    else if (n == 3)
    {
        rank = Card::TEN;
        suit = Card::suit_map.at(std::string(1, str[2]));
    }

    return Card(rank, suit);
}