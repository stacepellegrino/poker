#ifndef CLASS_GAME_IMP
#define CLASS_GAME_IMP

#include <iostream>

#include <stdlib.h>

#include "game.h"

bool checkstatus;
bool raisestatus;
bool blindstatus;
bool flopstatus;

int the_largest_bet;

int comparesuit(const void *card1, const void *card2)
{
  return (*(Xcard*)card1).get_suit() - (*(Xcard*)card2).get_suit();
}

int comparerank(const void *card1, const void *card2)
{
  return (*(Xcard*)card1).get_rank() - (*(Xcard*)card2).get_rank();
}

Game::Game()
{
  the_player_index = 0;
  checkstatus = false;
  raisestatus = false;
  blindstatus = false;
  the_largest_bet = 0;
  flopstatus = false;
}

void Game::play(double blind, double money, std::string name1, std::string name2)
{
  the_players[0] = Xplayer();
  the_players[1] = Xplayer();

  the_players[0].set_name(name1);
  the_players[1].set_name(name2);

  the_players[0].set_money(money);
  the_players[1].set_money(money);

  the_players[0].set_playing(true);
  the_players[1].set_playing(true);

  the_table.set_blind(blind);

  Xtable::Game_status game_is = Xtable::PLAYABLE;
  while (game_is == Xtable::PLAYABLE)
  {
    while (the_table.get_players() > 1)
    {
      the_table.set_round(the_table.get_round() + 1);

      the_player_index++;
      the_table.set_blind_index(the_table.get_blind_index() + 1);

      Game::blind();

      the_deck.shuffle();
      Game::deal();
      the_players[the_player_index % 2].set_cards_visible(false);
      the_players[the_player_index % 2].set_cards_visible(true);
      the_table.screensaver(the_screen);
      the_screen.cont(the_players[the_player_index % 2].get_name() + " input the character 'c' to continue and see your cards: "); 
      the_table.reset_cards();
      the_table.display(the_screen, the_players[0], the_players[1]);
      Game::bet();

      if (the_table.get_players() > 1)
      {
        the_table.flop(the_deck);
        flopstatus = true;

        the_table.screensaver(the_screen);
        the_screen.cont(the_players[the_player_index % 2].get_name() + " input the character 'c' to continue and see your cards: "); 
        the_table.display(the_screen, the_players[0], the_players[1]);

        Game::bet();
      }

      if (the_table.get_players() > 1)
      {
        the_table.turn(the_deck);

        the_table.screensaver(the_screen);
        the_screen.cont(the_players[the_player_index % 2].get_name() + " input the character 'c' to continue and see your cards: "); 
        the_table.display(the_screen, the_players[0], the_players[1]);

        Game::bet();
      }

      if (the_table.get_players() > 1)
      {
        the_table.river(the_deck);

        the_table.screensaver(the_screen);
        the_screen.cont(the_players[the_player_index % 2].get_name() + " input the character 'c' to continue and see your cards: "); 
        the_table.display(the_screen, the_players[0], the_players[1]);

        Game::bet();
      }

      Game::evaluate();
    }

    if (the_table.get_players() == 1)
    {
        the_players[the_player_index % 2].set_cards_visible(true);
        the_player_index++;
        the_players[the_player_index % 2].set_cards_visible(true);
        the_table.screensaver(the_screen);
        the_screen.cont("Input the character 'c' to continue and see all cards: "); 
        the_table.display(the_screen, the_players[0], the_players[1]);
        the_screen.cont("Input the character 'c' to continue: "); 
    }

    the_players[0].set_playing(true);
    the_players[1].set_playing(true);
    the_table.set_players(2);
    the_player_index++;
    checkstatus = false;
    raisestatus = false;
    flopstatus = false;
    the_table.reset_cards();
  }
}

void Game::blind()
{

  for (int i = 0; i < 2; i++)
  {
    the_players[(the_table.get_blind_index() + i) % 2].set_bet(the_table.get_blind() * (i + 1));
    the_players[(the_table.get_blind_index() + i) % 2].set_money(the_players[(the_table.get_blind_index() + i) % 2].get_money() - the_players[(the_table.get_blind_index() + i) % 2].get_bet());
    the_table.set_pot(the_table.get_pot() + the_players[(the_table.get_blind_index() + i) % 2].get_bet());
    the_players[(the_table.get_blind_index() + i) % 2].set_total_bet(the_players[(the_table.get_blind_index() + i) % 2].get_total_bet() + the_players[(the_table.get_blind_index() + i) % 2].get_bet());

  }

  the_player_index = the_table.get_blind_index() + 1;

  blindstatus = true;
}

void Game::deal()
{
  for (int i = 0; i < 2; i++)
  {
    for (int j = the_player_index; j < the_player_index + 2; j++)
    {
      the_players[j % 2].set_card(i, the_deck.draw());
    }
  }
}

void Game::bet()
{
  if (checkstatus == true || raisestatus == true)
  {
    the_screen.message(the_players[the_player_index % 2].get_name());
    the_screen.message( ":");
    the_screen.menu("Fold", "Check", "Raise");
    switch (the_screen.event())
    {
      case TUI::M_1 :
        Game::fold();
        break;
     case TUI::M_2 :
        Game::check();
        break;
     case TUI::M_3 :
        Game::raise();
        break;
    }
  }
  else
  {
    the_screen.message(the_players[the_player_index % 2].get_name());
    the_screen.message( ":");
    the_screen.menu("Fold", "Call", "Raise");
    switch (the_screen.event())
    {
      case TUI::M_1 :
        Game::fold();
        break;
     case TUI::M_2 :
        Game::call();
        break;
     case TUI::M_3 :
        Game::raise();
        break;
    } 
  }
}

void Game::fold()
{
  the_players[the_player_index % 2].set_playing(false);
  the_players[the_player_index % 2].set_cards_visible(false);
  the_player_index++;
  the_players[the_player_index % 2].set_cards_visible(true);
  the_table.set_players(the_table.get_players() - 1);
}

void Game::check()
{

  the_players[the_player_index % 2].set_cards_visible(false);
  the_player_index++;
  the_players[the_player_index % 2].set_cards_visible(true);

  if ((checkstatus == true && flopstatus == true) || (raisestatus == true && flopstatus == true))
  {
    the_table.screensaver(the_screen);
    the_screen.cont(the_players[the_player_index % 2].get_name() + " input the character 'c' to continue and see your cards: "); 
    the_table.display(the_screen, the_players[0], the_players[1]);

    the_screen.message(the_players[the_player_index % 2].get_name());
    the_screen.message( ":");
    the_screen.menu("Fold", "Check", "Raise");

    switch (the_screen.event())
    {
      case TUI::M_1 :
        Game::fold();
        break;
      case TUI::M_2 :


        the_players[the_player_index % 2].set_cards_visible(false);
        the_player_index++;
        the_players[the_player_index % 2].set_cards_visible(true);
        break;
     case TUI::M_3 :
        raisestatus = true;
        Game::raise();
        break;
    }
  }
}

void Game::call()
{
  if (blindstatus == true && the_player_index % 2 == the_table.get_blind_index() % 2)
  {
    the_players[the_player_index % 2].set_bet(the_largest_bet + the_table.get_blind());
    blindstatus = false;
  }
  else
  {
    the_players[the_player_index % 2].set_bet(the_largest_bet);
  }

  the_largest_bet = 0;

  the_players[the_player_index % 2].set_money(the_players[the_player_index % 2].get_money() - the_players[the_player_index % 2].get_bet());
  the_table.set_pot(the_table.get_pot() + the_players[the_player_index % 2].get_bet());
  the_players[the_player_index % 2].set_total_bet(the_players[the_player_index % 2].get_total_bet() + the_players[the_player_index % 2].get_bet());

  the_players[the_player_index % 2].set_cards_visible(false);
  the_player_index++;
  the_players[the_player_index % 2].set_cards_visible(true);

  if (flopstatus == false && raisestatus == false)
  { 
    the_table.screensaver(the_screen);
    the_screen.cont(the_players[the_player_index % 2].get_name() + " input the character 'c' to continue and see your cards: "); 
    the_table.display(the_screen, the_players[0], the_players[1]);

    the_screen.message(the_players[the_player_index % 2].get_name());
    the_screen.message( ":");
    the_screen.menu("Fold", "Check", "Raise");
    switch (the_screen.event())
    {
      case TUI::M_1 :
        Game::fold();
        break;
     case TUI::M_2 :
        checkstatus = true;
        Game::check();
        break;
     case TUI::M_3 :
        raisestatus = true;
        Game::raise();
        break;
    } 
  }
}

void Game::allin()
{
  // TO BE IMPLEMENTED!
}

void Game::raise()
{
  int amount;

  the_screen.dialogue("Amount to raise", amount);
  if (amount > 0 && amount <= the_players[the_player_index % 2].get_money())
  {
    if (blindstatus == true && the_player_index % 2 == the_table.get_blind_index() % 2)
    {
      the_players[the_player_index % 2].set_bet(the_largest_bet + amount + the_table.get_blind());
      blindstatus = false;
    }
    else
    {
      the_players[the_player_index % 2].set_bet(the_largest_bet + amount);
    }

    the_largest_bet = amount;

    the_players[the_player_index % 2].set_money(the_players[the_player_index % 2].get_money() - the_players[the_player_index % 2].get_bet());
    the_table.set_pot(the_table.get_pot() + the_players[the_player_index % 2].get_bet());
    the_players[the_player_index % 2].set_total_bet(the_players[the_player_index % 2].get_total_bet() + the_players[the_player_index % 2].get_bet());

    the_players[the_player_index % 2].set_cards_visible(false);
    the_player_index++;
    the_players[the_player_index % 2].set_cards_visible(true);

    the_table.screensaver(the_screen);
    the_screen.cont(the_players[the_player_index % 2].get_name() + " input the character 'c' to continue and see your cards: "); 
    the_table.display(the_screen, the_players[0], the_players[1]);

    raisestatus = true;

    the_screen.message(the_players[the_player_index % 2].get_name());
    the_screen.message( ":");
    the_screen.menu("Fold", "Call", "Raise");
    switch (the_screen.event())
    {
      case TUI::M_1 :
        Game::fold();
        break;
     case TUI::M_2 :
        Game::call();
        break;
     case TUI::M_3 :
        Game::raise();
        break;
    }
  }
  else
  {
    the_screen.message("Invalid input");
    Game::raise();
  } 
}

void Game::evaluate()
{
  Xcard cards[7];
  Xcard high;
  Xcard _high;

  bool high_card, one_pair, two_pairs, _two_pairs, three_of_a_kind, _three_of_a_kind, straight, flush, full_house, four_of_a_kind, straight_flush, royal_flush;


  if (the_table.get_players() == 1 && the_players[the_player_index % 2].get_playing() == true)
  {
    the_players[the_player_index % 2].set_money(the_players[the_player_index % 2].get_money() + the_table.get_pot());
    the_table.set_pot(0);
  }
  else if (the_table.get_players() > 1)
  {
    for (int index = 0; index < 2; index++)
    {
      high_card = one_pair = two_pairs = _two_pairs = three_of_a_kind = _three_of_a_kind = straight = flush = full_house = four_of_a_kind = straight_flush = royal_flush = false;

      if (the_players[(the_player_index + index) % 2].get_playing() == true)
      {
        for (int i = 0; i < 5; i++)
        {
          cards[i] = the_table.get_card(i);
        }

        for (int i = 0; i < 2; i++)
        {
          cards[i + 5] = the_players[(the_player_index + index) % 2].get_card(i);
        }

        qsort(cards, 7, sizeof(Xcard), comparesuit);
        qsort(cards, 7, sizeof(Xcard), comparerank);

        for (int i = 0; i < 6; i++)
        {
          if (three_of_a_kind == true && cards[i].get_rank() == cards[i + 1].get_rank() && cards[i + 1].get_rank() == cards[i - 2].get_rank()) 
          {
            one_pair = two_pairs = three_of_a_kind = false;
            four_of_a_kind = true;
            high = cards[i];
            break;
          }
          else if (three_of_a_kind == true && cards[i].get_rank() == cards[i + 1].get_rank() && cards[i].get_rank() == cards[i + 2].get_rank())
          {
            one_pair = false;
            _three_of_a_kind = true;
            i++;
            _high = high;
            high = cards[i];
            continue;
          }
          else if (three_of_a_kind == false && two_pairs == true && cards[i].get_rank() == cards[i + 1].get_rank() && cards[i].get_rank() == cards[i + 2].get_rank()) 
          {
            three_of_a_kind = true;
            i++;
            _high = high;
            high = cards[i];
            continue;
          }
          else if (three_of_a_kind == false && one_pair == true && cards[i].get_rank() == cards[i + 1].get_rank() && cards[i].get_rank() == cards[i - 1].get_rank()) 
          {
            one_pair = false;
            three_of_a_kind = true;
            _high = high;
            high = cards[i];
            continue;
          }
          else if (three_of_a_kind == false && two_pairs == true && cards[i].get_rank() == cards[i + 1].get_rank() && cards[i].get_rank() == cards[i - 1].get_rank())
          {
            one_pair = true;
            two_pairs = false;
            three_of_a_kind = true;
            high = cards[i];
            continue;
          }
          else if (two_pairs == true && cards[i].get_rank() == cards[i + 1].get_rank())
          {
            two_pairs = false;
            _two_pairs = true;
            _high = high;
            high = cards[i];
          }
          else if (one_pair == true && cards[i].get_rank() != cards[i + 1].get_rank() && cards[i + 1].get_rank() == cards[i + 2].get_rank())
          {
            one_pair = false;
            two_pairs = true;
            i++;
            if (three_of_a_kind == false) {
              high = cards[i];
            }
            continue;
          }
          else if (one_pair == false && two_pairs == false && cards[i].get_rank() == cards[i + 1].get_rank())
          {
            one_pair = true;
            _high = cards[i];
            if (three_of_a_kind == false)
            {
              high = cards[i];
            }
            continue;
          }
        }

        if (((one_pair == true || two_pairs == true) && three_of_a_kind == true) || (three_of_a_kind == true && _three_of_a_kind == true))
        {
          full_house = true;
        }

        bool ace_one;

        ace_one = false;

        qsort(cards, 7, sizeof(Xcard), comparerank);

        for (int i = 0; i < 6; i++)
        {
          if (cards[i].get_rank() == cards[i + 1].get_rank() - 1 && cards[i].get_suit() == cards[i + 1].get_suit() && cards[i].get_rank() == cards[i + 2].get_rank() -2 && cards[i].get_suit() == cards[i + 2].get_suit() && cards[i].get_rank() == cards[i + 3].get_rank() - 3 && cards[i].get_suit() == cards[i + 3].get_suit() && cards[i].get_rank() == cards[i + 4].get_rank() - 4 && cards[i].get_suit() == cards[i + 4].get_suit())
          {
            straight_flush = true;
            high = cards[i + 4]; 

            if (cards[i].get_rank() == cards[i + 5].get_rank() - 5 && cards[i].get_suit() == cards[i + 5].get_suit())
            {
              high = cards[i + 5];

              if (cards[i].get_rank() == cards[i + 6].get_rank() - 6 && cards[i].get_suit() == cards[i + 6].get_suit())
              {
                high = cards[i + 6];
              }
            }
          }
          else if (cards[i].get_rank() == Xcard::TWO && cards[i + 1].get_rank() == Xcard::THREE && cards[i].get_suit() == cards[i + 1].get_suit() && cards[i + 2].get_rank() == Xcard::FOUR && cards[i].get_suit() == cards[i + 2].get_suit() && cards[i + 3].get_rank() == Xcard::FIVE && cards[i].get_suit() == cards[i + 3].get_suit())
          {
            ace_one = true;
            high = cards[i + 3]; 
          }

          if (ace_one == true && cards[i + 1].get_rank() == Xcard::ACE && cards && cards[i - 3].get_suit() == cards[i + 1].get_suit())
          {
            straight_flush = true;
          }
        }

        if (straight_flush == true && high.get_rank() == Xcard::ACE)
        {
          straight_flush = false;
          royal_flush = true;
        }

        if (royal_flush == false && straight_flush == false)
        {
          qsort(cards, 7, sizeof(Xcard), comparesuit);

          for (int i = 0; i < 3; i++)
          {
            if (cards[i].get_suit() == cards[i + 1].get_suit() && cards[i].get_suit() == cards[i + 2].get_suit() && cards[i].get_suit() == cards[i + 3].get_suit() && cards[i].get_suit() == cards[i + 4].get_suit())
            {
              flush = true;
              high = cards[i + 4];

              if (cards[i].get_suit() == cards[6].get_suit())
              {
                high = cards[6];
              }
              else if (cards[i].get_suit() == cards[5].get_suit())
              {
                high = cards[5];
              }
            }
          }

          if (flush == true)
          {
            one_pair = two_pairs = three_of_a_kind = false;
          }

          ace_one = false;

          qsort(cards, 7, sizeof(Xcard), comparerank);

          if (flush == false)
          {
            for (int i = 0; i < 3; i++)
            {
              if (cards[i].get_rank() == cards[i + 1].get_rank() - 1 && cards[i].get_rank() == cards[i + 2].get_rank() - 2 && cards[i].get_rank() == cards[i + 3].get_rank() - 3 && cards[i].get_rank() == cards[i + 4].get_rank() - 4)
              {
                straight = true;
                high = cards[i + 4]; 

                if (cards[i].get_rank() == cards[i + 5].get_rank() - 5)
                {
                  high = cards[i + 5];

                  if (cards[i].get_rank() == cards[i + 6].get_rank() - 6)
                  {
                    high = cards[i + 6];
                  }
                }
              }

              if (cards[i].get_rank() == Xcard::TWO && cards[i + 1].get_rank() == Xcard::THREE && cards[i + 2].get_rank() == Xcard::FOUR && cards[i + 3].get_rank() == Xcard::FIVE)
              {
                ace_one = true;
              }

              if (ace_one == true && cards[i + 1].get_rank() == Xcard::ACE)
              {
                straight = true;
                high = cards[i + 3]; 
              }
            }
          }
        }

        if (royal_flush == true || straight_flush == true) 
        {
          one_pair = two_pairs = three_of_a_kind = straight = flush = full_house = four_of_a_kind = false;
        }

        if (flush == true || straight == true)
        {
          one_pair = two_pairs = three_of_a_kind = false;
        }

        if (royal_flush == true)
        {
          the_players[(the_player_index + index) % 2].set_hand(Player::ROYAL_FLUSH);
        }

        if (straight_flush == true)
        {
          the_players[(the_player_index + index) % 2].set_hand(Player::STRAIGHT_FLUSH);
        }

        if (flush == true)
        {
          the_players[(the_player_index + index) % 2].set_hand(Player::FLUSH);
        }

        if (straight == true)
        {
          the_players[(the_player_index + index) % 2].set_hand(Player::STRAIGHT);
        }

        if (one_pair == true)
        {
          the_players[(the_player_index + index) % 2].set_hand(Player::ONE_PAIR);
        }

        if (three_of_a_kind == true)
        {
          the_players[(the_player_index + index) % 2].set_hand(Player::THREE_OF_A_KIND);
        }

        if (_three_of_a_kind == true)
        {
          the_players[(the_player_index + index) % 2].set_hand(Player::FULL_HOUSE);
        }

        if (four_of_a_kind == true)
        {
          the_players[(the_player_index + index) % 2].set_hand(Player::FOUR_OF_A_KIND);
        }

        if (_two_pairs == true)
        {
          the_players[(the_player_index + index) % 2].set_hand(Player::TWO_PAIRS);
        }

        if (two_pairs == true)
        {
          the_players[(the_player_index + index) % 2].set_hand(Player::TWO_PAIRS);
        }

        if (full_house == true)
        {
          the_players[(the_player_index + index) % 2].set_hand(Player::FULL_HOUSE);
        }

        if (royal_flush == false && straight_flush == false && four_of_a_kind == false && full_house == false && flush == false && straight == false && three_of_a_kind == false && two_pairs == false && one_pair == false)
        {
          the_players[(the_player_index + index) % 2].set_hand(Player::HIGH_CARD);
          high = cards[6];
        }

        the_players[(the_player_index + index) % 2].set_high(high);

        if (full_house == true || two_pairs == true || _two_pairs == true)
        {
          the_players[(the_player_index + index) % 2].set_next_high(_high); 
        }
      }
    }

    the_players[the_player_index % 2].set_cards_visible(true);
    the_player_index++;
    the_players[the_player_index % 2].set_cards_visible(true);
    the_table.screensaver(the_screen);
    the_screen.cont("Input the character 'c' to continue and see all cards: "); 
    the_table.display(the_screen, the_players[0], the_players[1]);

    if (the_players[the_player_index % 2].get_hand() > the_players[(the_player_index + 1) % 2].get_hand())
    {
      the_players[the_player_index % 2].set_money(the_players[the_player_index % 2].get_money() + the_table.get_pot());
      the_table.set_pot(0);
      the_screen.message(the_players[the_player_index % 2].get_name() + " wins with a " + the_players[the_player_index % 2].view_hand());
    }
    else if (the_players[the_player_index % 2].get_hand() < the_players[(the_player_index + 1) % 2].get_hand())
    {
      the_players[(the_player_index + 1) % 2].set_money(the_players[(the_player_index + 1) % 2].get_money() + the_table.get_pot());
      the_table.set_pot(0);
      the_screen.message(the_players[(the_player_index + 1) % 2].get_name() + " wins with a " + the_players[(the_player_index + 1) % 2].view_hand());
    }
    else if (the_players[the_player_index % 2].get_hand() == the_players[(the_player_index + 1) % 2].get_hand())
    {
      // evaluate high cards then kickers here
      if (the_players[the_player_index % 2].get_high().get_rank() > the_players[(the_player_index + 1) % 2].get_high().get_rank())
      {
        the_players[the_player_index % 2].set_money(the_players[the_player_index % 2].get_money() + the_table.get_pot());
        the_table.set_pot(0);
        the_screen.message(the_players[the_player_index % 2].get_name() + " wins with a " + the_players[the_player_index % 2].view_hand());
      }
      else if (the_players[the_player_index % 2].get_high().get_rank() < the_players[(the_player_index + 1) % 2].get_high().get_rank())
      {
        the_players[(the_player_index + 1) % 2].set_money(the_players[(the_player_index + 1) % 2].get_money() + the_table.get_pot());
        the_table.set_pot(0);
        the_screen.message(the_players[(the_player_index + 1) % 2].get_name() + " wins with a " + the_players[(the_player_index + 1) % 2].view_hand());
      }
      else if (the_players[the_player_index % 2].get_high().get_rank() == the_players[(the_player_index + 1) % 2].get_high().get_rank())
      {

        the_players[the_player_index % 2].set_money(the_players[the_player_index % 2].get_money() + (the_table.get_pot() / 2));

        the_players[(the_player_index + 1) % 2].set_money(the_players[(the_player_index + 1) % 2].get_money() + (the_table.get_pot() / 2));

        the_table.set_pot(0);

        the_screen.message(the_players[the_player_index % 2].get_name() + " and " + the_players[(the_player_index + 1) % 2].get_name() + " both draw with a " + the_players[the_player_index % 2].view_hand());
      }
    }
    the_screen.cont("Input the character 'c' to continue: ");
  }
}

#endif
