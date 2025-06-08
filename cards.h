#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Card{
    public:
        enum Rank{
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
        enum Suit{
            HEARTS,
            DIAMONDS,
            SPADES,
            CLUBS
        };
        Card(Rank rank, Suit suit) : _rank(rank), _suit(suit) {}

        friend std::ostream& operator<<(std::ostream& os, const Card& card){
            switch (card._rank){
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
            switch(card._suit){
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

        friend std::wostream& operator<<(std::wostream& os, const Card& card){
            
            switch (card._rank){
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
            switch(card._suit){
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

        bool operator==(const Card other) { return _rank == other._rank && _suit == other._suit;}
        bool operator<(const Card other) {return _rank < other._rank;}
        
    private:
        Rank _rank;
        Suit _suit;
};

Card operator""_card(const char* str, std::size_t n) {}

class Hand{
    Hand(std::vector<Card> cards) : cards(cards) {
        std::sort(cards.begin(), cards.end());
};



    public:
        std::vector<Card> cards;
};


#endif