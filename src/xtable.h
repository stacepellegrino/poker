#ifndef CLASS_XTABLE_SPEC
#define CLASS_XTABLE_SPEC

#include "table.h"
#include "xplayer.h"
#include "tui.h"

class Xtable : public Table {
public:
  void display(TUI&, Xplayer&, Xplayer&);
  void screensaver(TUI&);
private:
};

#endif
