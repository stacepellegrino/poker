#ifndef CLASS_GAME_SPEC
#define CLASS_GAME_SPEC

#include "xplayer.h"
#include "xtable.h"
#include "deck.h"

#include "tui.h"

#include <string>

class Game {
public:
  Game();
  void play(double, double, std::string, std::string);
  void blind();
  void deal();
  void bet();
  void fold();
  void check();
  void call();
  void allin();
  void raise();
  void evaluate();
private:
  TUI the_screen;
  Xtable the_table;
  Deck the_deck;
  Xplayer the_players[2];
  int the_player_index;			// The current player
};

#endif
