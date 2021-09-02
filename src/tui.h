#ifndef CLASS_TUI_SPEC
#define CLASS_TUI_SPEC

#include <string>

class TUI
{
public:
  enum Menu_item { M_NONE, M_1, M_2, M_3, M_4, M_5, M_6 };
  TUI();
  void menu(std::string="", std::string="", std::string="",
            std::string="", std::string="", std::string="");
  Menu_item event();
  void message(std::string);
  void dialogue(std::string, int&);
  void cont(std::string);
protected:
  void display_menu_item(std::string, std::string);
private:
  std::string the_men_1, the_men_2, the_men_3;
  std::string the_men_4, the_men_5, the_men_6;
};

#endif
