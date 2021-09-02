#ifndef CLASS_DECK_SPEC
#define CLASS_DECK_SPEC

#include "xcard.h"

class Deck {
public:
  Deck();
  void shuffle();
  Xcard draw();
private:
  Xcard the_cards[52];
  int index;
};

#endif
