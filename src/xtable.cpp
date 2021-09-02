#ifndef CLASS_XTABLE_IMP
#define CLASS_XTABLE_IMP

#include "xtable.h"
#include "tui.h"
#include <strstream>

void Xtable::display(TUI &vdu, Xplayer &player1, Xplayer &player2)
{
  const int MAX_BUF = 1024;
  char buf[MAX_BUF];
  std::ostrstream text(buf, MAX_BUF);

  text << "\n";
  text << "Round: " << get_round();
  text << "\n";
  text << "                    ";
  text << player1.get_name() << ": $" << player1.get_money();
  text << "\n";
  text << "                    ";
  text << " ___   ___";
  text << "\n";
  text << "                    ";
  if (player1.get_cards_visible() == true)
  {
    text << "| " << player1.get_card(0).view_rank() << " | | " << player1.get_card(1).view_rank() << " |";
    text << "\n";
    text << "                    ";
    text << "| " << player1.get_card(0).view_suit() << " | | " << player1.get_card(1).view_suit() << " |";
  }
  else
  {
    text << "|   | |   |";
    text << "\n";
    text << "                    ";
    text << "|   | |   |";
  }
  text << "\n";
  text << "                    ";
  text << "|___| |___|";
  text << "\n";
  text << "\n";
  text << "                    ";
  text << " ___   ___   ___   ___   ___";
  text << "\n";
  text << "                    ";
  text << "| " << get_card(0).view_rank() << " | | " << get_card(1).view_rank() << " | | " << get_card(2).view_rank() << " | | " << get_card(3).view_rank() << " | | " << get_card(4).view_rank() << " |";
  text << "\n";
  text << "                    ";
  text << "| " << get_card(0).view_suit() << " | | " << get_card(1).view_suit() << " | | " << get_card(2).view_suit() << " | | " << get_card(3).view_suit() << " | | " << get_card(4).view_suit() << " | Pot: $" << get_pot();
  text << "\n";
  text << "                    ";
  text << "|___| |___| |___| |___| |___|";
  text << "\n";
  text << "\n";
  text << "                    ";
  text << " ___   ___";
  text << "\n";
  text << "                    ";
  if (player2.get_cards_visible() == true)
  {
    text << "| " << player2.get_card(0).view_rank() << " | | " << player2.get_card(1).view_rank() << " |";
  text << "\n";
  text << "                    ";
  text << "| " << player2.get_card(0).view_suit() << " | | " << player2.get_card(1).view_suit() << " |";
  }
  else
  {
    text << "|   | |   |";
    text << "\n";
    text << "                    ";
    text << "|   | |   |";
  }
  text << "\n";
  text << "                    ";
  text << "|___| |___|";
  text << "\n";
  text << "\n";
  text << "                    ";
  text << player2.get_name() << ": $" << player2.get_money();
  text << "\n";
  text << "\n";
  text << '\0';

  vdu.message(text.str());
}

void Xtable::screensaver(TUI &vdu)
{
  const int MAX_BUF = 1024;
  char buf[MAX_BUF];
  std::ostrstream text(buf, MAX_BUF);

  for (int i = 0; i < 24; i++)
  {
    text << "\n";
  }

  text << '\0';

  vdu.message(text.str());
}

#endif
