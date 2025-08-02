#include "cards.h"

Card::Card(Card::Rank rank, Card::Suit suit) : rank(rank), suit(suit) {}

std::ostream &operator<<(std::ostream &os, const Card &card)
{
    switch (card.rank)
    {
    case Card::Rank::TWO:
        os << "2";
        break;
    case Card::Rank::THREE:
        os << "3";
        break;
    case Card::Rank::FOUR:
        os << "4";
        break;
    case Card::Rank::FIVE:
        os << "5";
        break;
    case Card::Rank::SIX:
        os << "6";
        break;
    case Card::Rank::SEVEN:
        os << "7";
        break;
    case Card::Rank::EIGHT:
        os << "8";
        break;
    case Card::Rank::NINE:
        os << "9";
        break;
    case Card::Rank::TEN:
        os << "10";
        break;
    case Card::Rank::JACK:
        os << "J";
        break;
    case Card::Rank::QUEEN:
        os << "Q";
        break;
    case Card::Rank::KING:
        os << "K";
        break;
    case Card::Rank::ACE:
        os << "A";
        break;
    default:
        os << "?";
        break;
    }
    switch (card.suit)
    {
    case Card::HEARTS:
        os << "H";
        break;
    case Card::DIAMONDS:
        os << "D";
        break;
    case Card::SPADES:
        os << "S";
        break;
    case Card::CLUBS:
        os << "C";
        break;
    }
    return os;
}

std::wostream &operator<<(std::wostream &os, const Card &card)
{
    switch (card.rank)
    {
    case Card::Rank::TWO:
        os << "2";
        break;
    case Card::Rank::THREE:
        os << "3";
        break;
    case Card::Rank::FOUR:
        os << "4";
        break;
    case Card::Rank::FIVE:
        os << "5";
        break;
    case Card::Rank::SIX:
        os << "6";
        break;
    case Card::Rank::SEVEN:
        os << "7";
        break;
    case Card::Rank::EIGHT:
        os << "8";
        break;
    case Card::Rank::NINE:
        os << "9";
        break;
    case Card::Rank::TEN:
        os << "10";
        break;
    case Card::Rank::JACK:
        os << "J";
        break;
    case Card::Rank::QUEEN:
        os << "Q";
        break;
    case Card::Rank::KING:
        os << "K";
        break;
    case Card::Rank::ACE:
        os << "A";
        break;
    default:
        os << "?";
        break;
    }
    switch (card.suit)
    {
    case Card::HEARTS:
        os << L"♥";
        break;
    case Card::DIAMONDS:
        os << L"♦";
        break;
    case Card::SPADES:
        os << L"♠";
        break;
    case Card::CLUBS:
        os << L"♣";
        break;
    }
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