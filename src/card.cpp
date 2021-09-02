#ifndef CLASS_CARD_IMP
#define CLASS_CARD_IMP

#include "card.h"

Card::Card()
{
  the_rank; 
  the_suit;
}
  
void Card::set_rank(Card::Card_rank rank)
{
  the_rank = rank;
}

void Card::set_suit(Card::Card_suit suit)
{
  the_suit = suit;
}

Card::Card_rank Card::get_rank() const
{
  return the_rank;
}

Card::Card_suit Card::get_suit() const
{
  return the_suit;
}

#endif
