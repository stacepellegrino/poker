#ifndef CLASS_TABLE_SPEC
#define CLASS_TABLE_SPEC

#include "xcard.h"
#include "deck.h"

class Table {
public:
  enum Game_status { PLAYABLE };
  enum Game_result { WIN, DRAW };
  Table();
  void flop(Deck&);
  void turn(Deck&);
  void river(Deck&);
  void set_blind(double);
  double get_blind();
  void set_blind_index(int);
  int get_blind_index();
  void set_pot(double);
  double get_pot();
  void set_round(int);
  int get_round();
  void set_players(int);
  int get_players();
  void set_card(int, Xcard);
  Xcard get_card(int);
  void reset_cards();
  Game_status playable(); 
protected:
  // For inheritance
  const Xcard &content(const Xcard::Card_rank, const Xcard::Card_suit) const;
private:
  Xcard table_cards[5];
  double the_blind;
  int the_blind_index;
  double the_pot;
  int the_round;
  int the_players;
};

#endif
