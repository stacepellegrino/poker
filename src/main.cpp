#include "game.cpp"
#include "xtable.cpp"
#include "table.cpp"
#include "xplayer.cpp"
#include "player.cpp"
#include "deck.cpp"
#include "xcard.cpp"
#include "card.cpp"
#include "tui.cpp"

#include <getopt.h>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

bool validint(char *arg) {

  bool validint = false;
  for (int i = 0; i < strlen(arg); i++)
  {
    if (isdigit(arg[i]))
    {
      validint = true;
    }
    else
    {
      validint = false;
      break;
    }
  }
  return validint;
}

int main(int argc, char *argv[])
{


  int c;

  double blind;
  double money;

  char *b;
  char *m;

  string name1;
  string name2;
     
  while (1)
  {
    static struct option long_options[] =
    {
      {"blind",  required_argument, 0, 'b'},
      {"money",    required_argument, 0, 'm'},
      {0, 0}
    };

    int option_index = 0;
     
    c = getopt_long (argc, argv, "b:m:", long_options, &option_index);
     
    // Detect the end of the options.
    if (c == -1)
      break;
     
    switch (c)
    {
      case 0:
        if (long_options[option_index].flag != 0)
          break;
        case 'b':
          if (validint(optarg))
          {
            b = optarg;
          }
          else
          {
            cout << "Invalid option to -b, --blind. Must be an integer." << endl;
            return 1;
          }
          break;
        case 'm':
          if (validint(optarg))
          {
            m = optarg;
          }
          else
          {
            cout << "Invalid option to -b, --blind. Must be an integer." << endl;
            return 1;
          }
          break;
        case '?':
          break;
        default:
          abort ();
    }
  }
     
  if (optind != 5) {
    cout << "Invalid number of options." << endl << "Usage: poker --blind BLIND --money MONEY [NAME] [NAME]" << endl;
    return 1;
  }

  if (argc - optind != 2) {
    cout << "Invalid number of names. Must be two players names as arguments." << endl;
    return 1;
  }

  blind = stod(b);
  money = stod(m);

  name1 = argv[optind];
  name2 = argv[optind + 1];

  Game().play(blind, money, name1, name2);
  return 0;
}
