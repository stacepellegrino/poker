#ifndef CLASS_XCARD_SPEC
#define CLASS_XCARD_SPEC

#include "card.h"

class Xcard : public Card {
public:
  char view_rank() const;
  char view_suit() const;
private:
};

#endif
