#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include <map>
#include <string>
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
                {"A", ACE}
        };

        inline static const std::map<std::string, Suit> suit_map = {
                {"H", HEARTS},
                {"D", DIAMONDS},
                {"S", SPADES},
                {"C", CLUBS}
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
        
    friend Card operator""_card(const char* str, std::size_t n);

    private:
        Rank _rank;
        Suit _suit;
};

Card operator""_card(const char* str, std::size_t n) {
    // What the fuck
    // Never let bro cook again
    // No verification, who cares tbh
    // Maybe I'll implement static checking in the future
    Card::Rank rank;
    Card::Suit suit;
    
    if (n == 2) {
        rank = Card::rank_map.at(std::string(1, str[0]));
        suit = Card::suit_map.at(std::string(1, str[1]));
    }
    else if (n == 3) {
        rank = Card::TEN;
        suit = Card::suit_map.at(std::string(1, str[2]));
    }

    return Card(rank, suit);
}

class Hand{
    Hand(std::vector<Card> cards) : cards(cards) {
        std::sort(cards.begin(), cards.end());
};



    public:
        std::vector<Card> cards;
};


#endif