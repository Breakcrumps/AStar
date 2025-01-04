#pragma once

#include "structs.h"
#include <vector>

using std::vector;

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

int human_function(
  Pos start_pos,
  vector<int> const (&human_field)[],
  int max_turns,
  int height,
  int length
);

int mouse_function(
  Pos start_pos,
  vector<int> const (&mouse_field)[],
  int max_turns,
  int height,
  int length
);