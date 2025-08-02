#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <vector>
#include <algorithm>

#include "cards.h"
#include "hand.h"

using enum Card::Suit;
using enum Card::Rank;
using namespace std;
int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    Hand hand{{"10S"_card, "9H"_card, "QC"_card, "5H"_card}};

    // hand.get_subhand(Card::HEARTS);

    




}