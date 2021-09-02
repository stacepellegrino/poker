#ifndef CLASS_TUI_IMP
#define CLASS_TUI_IMP

#include "tui.h"
#include <iostream>
#include <string>

TUI::TUI()
{
  the_men_1 = the_men_2 = the_men_3 =
  the_men_4 = the_men_5 = the_men_6 = "";
}

void TUI::menu( std::string m1, std::string m2, std::string m3,
                std::string m4, std::string m5, std::string m6 )
{
  the_men_1 = m1; the_men_2 = m2; the_men_3 = m3;
  the_men_4 = m4; the_men_5 = m5; the_men_6 = m6;    // Store names 
}

TUI::Menu_item TUI::event()
{
  Menu_item choice = M_NONE;
  while ( choice == M_NONE )
  {
    display_menu_item(" (1) ", the_men_1);  // First menu item 
    display_menu_item(" (2) ", the_men_2);  // Second .. 
    display_menu_item(" (3) ", the_men_3);
    display_menu_item(" (4) ", the_men_4);
    display_menu_item(" (5) ", the_men_5);
    display_menu_item(" (6) ", the_men_6);
    char selection;
    std::cout << std::endl << "Input selection : ";
    std::cin >> selection;
    switch (selection)
    {
      case '1' :
        if (the_men_1 != "") choice = M_1;
        break;
      case '2' :
        if (the_men_2 != "") choice = M_2;
        break;
      case '3' :
        if (the_men_3 != "") choice = M_3;
        break;
      case '4' :
        if (the_men_4 != "") choice = M_4;
        break;
      case '5' :
        if (the_men_5 != "") choice = M_5;
        break;
      case '6' :
        if (the_men_6 != "") choice = M_6;
        break;
      default  :
        break;
    }
    if (choice == M_NONE)
      message("\nInvalid response\n\n");
  }
  return choice;                         // User selection 
}

void TUI::display_menu_item(std::string prompt, std::string name)
{
  if (name != "")                        // Not null std::string 
  {
    std::cout << prompt << name; 
  }
}

void TUI::message(std::string mes)
{
  std::cout << mes; // << "\n" << "\n";  // Message to user 
}

void TUI::dialogue(std::string mes, int &answer)
{
  std::cout << "\n" << mes << " : ";     // User prompt 
  std::cin >> answer;                    // Read user response 
  std::cout << "\n";
}

void TUI::cont(std::string mes)
{
  char c;
  std::cout << "\n" << mes;
  while (cin.get(c))
  {
    if (c == 'c') { break; }
  }
  std::cout << "\n";
}

#endif
