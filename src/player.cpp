#ifndef CLASS_PLAYER_IMP
#define CLASS_PLAYER_IMP

#include "player.h"

Player::Player()
{
  blind = false;
  the_total_bet = 0;
  cards_visible = false;
}

void Player::set_name(std::string name)
{
  the_name = name;
}

std::string Player::get_name()
{
  return the_name;
}

void Player::set_money(double money)
{
  the_money = money;
}

double Player::get_money()
{
  return the_money;
}

void Player::set_card(int index, Xcard card)
{
   the_cards[index] = card;
}

Xcard Player::get_card(int index)
{
  return the_cards[index];
}

void Player::set_bet(double amount)
{
  the_bet = amount;
}

double Player::get_bet()
{
  return the_bet;
}

void Player::set_total_bet(double amount)
{
  the_total_bet = amount;
}

double Player::get_total_bet()
{
  return the_total_bet;
}

void Player::set_blind(bool what)
{
  blind = what;
}

bool Player::get_blind()
{
  return blind;
}

void Player::set_playing(bool what)
{
  playing = what;
}

bool Player::get_playing()
{
  return playing;
}

void Player::set_cards_visible(bool what)
{
  cards_visible = what;
}

bool Player::get_cards_visible()
{
  return cards_visible;
}

void Player::set_hand(Player::Hand hand)
{
  the_hand = hand;
}

Player::Hand Player::get_hand()
{
  return the_hand;
}

void Player::set_high(Xcard card)
{
  the_high = card;
}

Xcard Player::get_high()
{
  return the_high;
}

void Player::set_next_high(Xcard card)
{
  the_next_high = card;
}

Xcard Player::get_next_high()
{
  return the_next_high;
}

#endif
