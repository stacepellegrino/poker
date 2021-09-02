#ifndef CLASS_DECK_IMP
#define CLASS_DECK_IMP

#include "deck.h"
#include "card.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Deck::Deck()
{
  the_cards[0].set_rank(Xcard::ACE);
  the_cards[0].set_suit(Xcard::HEARTS);
  the_cards[1].set_rank(Xcard::KING);
  the_cards[1].set_suit(Xcard::HEARTS);
  the_cards[2].set_rank(Xcard::QUEEN);
  the_cards[2].set_suit(Xcard::HEARTS);
  the_cards[3].set_rank(Xcard::JACK);
  the_cards[3].set_suit(Xcard::HEARTS);
  the_cards[4].set_rank(Xcard::TEN);
  the_cards[4].set_suit(Xcard::HEARTS);
  the_cards[5].set_rank(Xcard::NINE);
  the_cards[5].set_suit(Xcard::HEARTS);
  the_cards[6].set_rank(Xcard::EIGHT);
  the_cards[6].set_suit(Xcard::HEARTS);
  the_cards[7].set_rank(Xcard::SEVEN);
  the_cards[7].set_suit(Xcard::HEARTS);
  the_cards[8].set_rank(Xcard::SIX);
  the_cards[9].set_suit(Xcard::HEARTS);
  the_cards[9].set_rank(Xcard::FIVE);
  the_cards[8].set_suit(Xcard::HEARTS);
  the_cards[10].set_rank(Xcard::FOUR);
  the_cards[10].set_suit(Xcard::HEARTS);
  the_cards[11].set_rank(Xcard::THREE);
  the_cards[11].set_suit(Xcard::HEARTS);
  the_cards[12].set_rank(Xcard::TWO);
  the_cards[12].set_suit(Xcard::HEARTS);

  the_cards[13].set_rank(Xcard::ACE);
  the_cards[13].set_suit(Xcard::DIAMONDS);
  the_cards[14].set_rank(Xcard::KING);
  the_cards[14].set_suit(Xcard::DIAMONDS);
  the_cards[15].set_rank(Xcard::QUEEN);
  the_cards[15].set_suit(Xcard::DIAMONDS);
  the_cards[16].set_rank(Xcard::JACK);
  the_cards[16].set_suit(Xcard::DIAMONDS);
  the_cards[17].set_rank(Xcard::TEN);
  the_cards[17].set_suit(Xcard::DIAMONDS);
  the_cards[18].set_rank(Xcard::NINE);
  the_cards[18].set_suit(Xcard::DIAMONDS);
  the_cards[19].set_rank(Xcard::EIGHT);
  the_cards[19].set_suit(Xcard::DIAMONDS);
  the_cards[20].set_rank(Xcard::SEVEN);
  the_cards[20].set_suit(Xcard::DIAMONDS);
  the_cards[21].set_rank(Xcard::SIX);
  the_cards[21].set_suit(Xcard::DIAMONDS);
  the_cards[22].set_rank(Xcard::FIVE);
  the_cards[22].set_suit(Xcard::DIAMONDS);
  the_cards[23].set_rank(Xcard::FOUR);
  the_cards[23].set_suit(Xcard::DIAMONDS);
  the_cards[24].set_rank(Xcard::THREE);
  the_cards[24].set_suit(Xcard::DIAMONDS);
  the_cards[25].set_rank(Xcard::TWO);
  the_cards[25].set_suit(Xcard::DIAMONDS);

  the_cards[26].set_rank(Xcard::ACE);
  the_cards[26].set_suit(Xcard::CLUBS);
  the_cards[27].set_rank(Xcard::KING);
  the_cards[27].set_suit(Xcard::CLUBS);
  the_cards[28].set_rank(Xcard::QUEEN);
  the_cards[28].set_suit(Xcard::CLUBS);
  the_cards[29].set_rank(Xcard::JACK);
  the_cards[29].set_suit(Xcard::CLUBS);
  the_cards[30].set_rank(Xcard::TEN);
  the_cards[30].set_suit(Xcard::CLUBS);
  the_cards[31].set_rank(Xcard::NINE);
  the_cards[31].set_suit(Xcard::CLUBS);
  the_cards[32].set_rank(Xcard::EIGHT);
  the_cards[32].set_suit(Xcard::CLUBS);
  the_cards[33].set_rank(Xcard::SEVEN);
  the_cards[33].set_suit(Xcard::CLUBS);
  the_cards[34].set_rank(Xcard::SIX);
  the_cards[34].set_suit(Xcard::CLUBS);
  the_cards[35].set_rank(Xcard::FIVE);
  the_cards[35].set_suit(Xcard::CLUBS);
  the_cards[36].set_rank(Xcard::FOUR);
  the_cards[36].set_suit(Xcard::CLUBS);
  the_cards[37].set_rank(Xcard::THREE);
  the_cards[37].set_suit(Xcard::CLUBS);
  the_cards[38].set_rank(Xcard::TWO);
  the_cards[38].set_suit(Xcard::CLUBS);

  the_cards[39].set_rank(Xcard::ACE);
  the_cards[39].set_suit(Xcard::SPADES);
  the_cards[40].set_rank(Xcard::KING);
  the_cards[40].set_suit(Xcard::SPADES);
  the_cards[41].set_rank(Xcard::QUEEN);
  the_cards[41].set_suit(Xcard::SPADES);
  the_cards[42].set_rank(Xcard::JACK);
  the_cards[42].set_suit(Xcard::SPADES);
  the_cards[43].set_rank(Xcard::TEN);
  the_cards[43].set_suit(Xcard::SPADES);
  the_cards[44].set_rank(Xcard::NINE);
  the_cards[44].set_suit(Xcard::SPADES);
  the_cards[45].set_rank(Xcard::EIGHT);
  the_cards[45].set_suit(Xcard::SPADES);
  the_cards[46].set_rank(Xcard::SEVEN);
  the_cards[46].set_suit(Xcard::SPADES);
  the_cards[47].set_rank(Xcard::SIX);
  the_cards[47].set_suit(Xcard::SPADES);
  the_cards[48].set_rank(Xcard::FIVE);
  the_cards[48].set_suit(Xcard::SPADES);
  the_cards[49].set_rank(Xcard::FOUR);
  the_cards[49].set_suit(Xcard::SPADES);
  the_cards[50].set_rank(Xcard::THREE);
  the_cards[50].set_suit(Xcard::SPADES);
  the_cards[51].set_rank(Xcard::TWO);
  the_cards[51].set_suit(Xcard::SPADES);

}

void Deck::shuffle()
{
  index = 51;
  srand(time(0));  // init seed randomly
  for (int i = 0; i < (52 - 1); i++) {
    int r = i + (rand() % (52 - i));
    Xcard tmp = the_cards[i];
    the_cards[i] = the_cards[r];
    the_cards[r] = tmp;
  }
}

Xcard Deck::draw()
{
  index--;
  return the_cards[index + 1];
}

#endif
