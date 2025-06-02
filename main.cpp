#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>
#include "cards.h"

using enum Card::Suit;
using enum Card::Rank;
using namespace std;
int main()
{
    // auto even = [](int i) { return 0 == i % 2; };
    // auto square = [](int i) { return i * i; };
 
    // std::vector<int> nums = {1, 2, 3, 4, 5, 6};
    // auto view = std::ranges::filter_view(nums, even);

    // for (auto elm : view){
    //     std::cout << elm << "\n";
    // }
    // std::cout << '\n';

    // std::cout << std::boolalpha;
    // Card card1{ACE, SPADES};
    // Card card2{ACE, SPADES};
    // Card card3{KING, DIAMONDS};
    // std::cout << "card1 == card2: " << (card1 == card2) << "\n";
    // std::cout << "card1 == card3: " << (card1 == card3) << "\n";

    std::vector<Card> hand{Card(EIGHT, DIAMONDS), Card(THREE, DIAMONDS), Card(EIGHT, SPADES), Card(JACK, CLUBS), Card(FOUR, HEARTS), Card(TEN, SPADES), Card(TEN, DIAMONDS), Card(EIGHT, HEARTS)};
    std::sort(hand.begin(), hand.end());

    for (auto card : hand) {
        std::wcout << Card(ACE, SPADES);
    }



}