#ifndef CLASS_XPLAYER_SPEC
#define CLASS_XPLAYER_SPEC

#include "player.h"

#include <string>

#include "tui.h"

class Xplayer : public Player {
public:
  std::string view_hand();
private:
};

#endif
