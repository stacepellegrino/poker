#ifndef CLASS_XPLAYER_IMP
#define CLASS_XPLAYER_IMP

#include <stdexcept>

#include "xplayer.h"

std::string Xplayer::view_hand()
{
  switch (get_hand())
  {
    case ROYAL_FLUSH     : return "royal flush";
    case STRAIGHT_FLUSH  : return "straight flush";
    case FOUR_OF_A_KIND  : return "four of a kind";
    case FULL_HOUSE      : return "full house";
    case FLUSH           : return "flush";
    case STRAIGHT        : return "straight";
    case THREE_OF_A_KIND : return "three of a kind";
    case TWO_PAIRS       : return "two pairs";
    case ONE_PAIR        : return "one pair";
    case HIGH_CARD       : return "high card";
    case NONE            : return "";
    default              : return "";
  }
}

#endif
