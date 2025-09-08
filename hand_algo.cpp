#include <sstream>
#include <string>


#include "cards.h"
#include "hand.h"

Hand Hand::get_subhand(Card::Suit suit) {
  Hand subhand;

  for (Card card : cards) {
    if (card.suit == suit) {
      subhand.cards.push_back(card);
    }
  }

  return subhand;
}

Hand Hand::get_subhand(Card::Rank rank) {
  Hand subhand;

  for (Card card : cards) {
    if (card.rank == rank) {
      subhand.cards.push_back(card);
    }
  }

  return subhand;
}

Hand Hand::find_best_hand() {
  Hand hearts_hand = get_subhand(Card::HEARTS);
  Hand diamonds_hand = get_subhand(Card::DIAMONDS);
  Hand spades_hand = get_subhand(Card::SPADES);
  Hand clubs_hand = get_subhand(Card::CLUBS);

  // Royal Flush
  return Hand{};
}