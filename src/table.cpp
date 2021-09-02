#ifndef CLASS_TABLE_IMP
#define CLASS_TABLE_IMP

#include "table.h"

Table::Table()
{
  the_pot = 0;
  the_round = 0;
  the_players = 2;
}

void Table::flop(Deck &deck)
{
  for (int i = 0; i < 3; i++)
  {
    set_card(i, deck.draw());
  }
}

void Table::turn(Deck &deck)
{
  set_card(3, deck.draw());
}

void Table::river(Deck &deck)
{
  set_card(4, deck.draw());
}

void Table::set_blind(double blind)
{
  the_blind = blind;
}

double Table::get_blind()
{
  return the_blind;
}

void Table::set_blind_index(int index)
{
  the_blind_index = index;
}

int Table::get_blind_index()
{
  return the_blind_index;
}

void Table::set_pot(double pot)
{
  the_pot = pot;
}

double Table::get_pot()
{
  return the_pot;
}

void Table::set_round(int round)
{
  the_round = round;
}

int Table::get_round()
{
  return the_round;
}

void Table::set_players(int players)
{
  the_players = players;
}

int Table::get_players()
{
  return the_players;
}

void Table::set_card(int i, Xcard card)
{
  table_cards[i] = card;
}

Xcard Table::get_card(int i)
{
  return table_cards[i];
}

void Table::reset_cards()
{
  Xcard card;
  card.set_rank(Xcard::RANKNONE);
  card.set_suit(Xcard::SUITNONE);
  for (int i =0; i < 5; i++)
  {
    table_cards[i] = card;
  }
}

Table::Game_status Table::playable()
{
  return PLAYABLE;
}

#endif
