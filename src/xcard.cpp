#ifndef CLASS_XCARD_IMP
#define CLASS_XCARD_IMP

#include "xcard.h"
#include <stdexcept>
  
char Xcard::view_rank() const
{
  switch (get_rank())
  {
    case ACE      : return 'A';
    case KING     : return 'K';
    case QUEEN    : return 'Q';
    case JACK     : return 'J';
    case TEN      : return 'T';
    case NINE     : return '9';
    case EIGHT    : return '8';
    case SEVEN    : return '7';
    case SIX      : return '6';
    case FIVE     : return '5';
    case FOUR     : return '4';
    case THREE    : return '3';
    case TWO      : return '2';
    case RANKNONE : return ' ';
    default    : //throw std::runtime_error("Card::view_rank");
                 return ' ';
  }
}

char Xcard::view_suit() const 
{
  switch (get_suit())
  {
    case HEARTS   : return 'H';
    case DIAMONDS : return 'D';
    case CLUBS    : return 'C';
    case SPADES   : return 'S';
    case SUITNONE : return ' ';
    default       : //throw std::runtime_error("Card::view_suit");
                    return ' ';
  }
}

#endif
