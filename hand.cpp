#include "hand.h"
#include "cards.h"

Hand Hand::get_subhand(Card::Suit suit){
    Hand subhand;

    for (Card card : cards) {
        if (card.suit == suit){
            subhand.cards.push_back(card);
        }
    }
}

Hand Hand::find_best_hand(){
    Hand hearts_hand = get_subhand(Card::HEARTS);

    // Royal Flush
}