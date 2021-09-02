#ifndef CLASS_PLAYER_SPEC
#define CLASS_PLAYER_SPEC

#include <string>

#include "xcard.h"

class Player {
public:
  enum Hand { NONE = 0, HIGH_CARD = 1, ONE_PAIR = 2, TWO_PAIRS = 3, THREE_OF_A_KIND = 4, STRAIGHT = 5, FLUSH = 6, FULL_HOUSE = 7, FOUR_OF_A_KIND = 8, STRAIGHT_FLUSH = 9, ROYAL_FLUSH = 10 };
  Player();
  void set_name(std::string);           
  std::string get_name();
  void set_money(double);           
  double get_money();
  void set_card(int, Xcard);           
  Xcard get_card(int);
  void set_bet(double);           
  double get_bet();
  void set_total_bet(double);           
  double get_total_bet();
  void set_blind(bool);           
  bool get_blind();
  void set_playing(bool);           
  bool get_playing();
  void set_cards_visible(bool);           
  bool get_cards_visible();
  void set_hand(Hand);
  Hand get_hand();
  void set_high(Xcard);
  Xcard get_high();
  void set_next_high(Xcard);
  Xcard get_next_high();
private:
  std::string the_name;
  double the_money;
  Xcard the_cards[2];
  double the_bet;
  double the_total_bet;
  bool blind;
  bool playing;
  bool cards_visible;
  Hand the_hand;
  Xcard the_high;
  Xcard the_next_high;
};

#endif
