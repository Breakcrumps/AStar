#pragma once

#include <unordered_map>
#include <vector>
#include "structs.h"
#include "common_funcs.h"

using std::vector, std::unordered_map, std::pair;

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

bool human_pos_is_good(
  vector<int> const (&human_field)[],
  unordered_map<Pos, Pos, HashPos>& came_from,
  unordered_map<Pos, int, HashPos>& cost_so_far,
  Node const (&current_node),
  Pos next_pos,
  int length, int height
);

bool human_second_pos_is_good(
  vector<int> const (&human_field)[],
  Pos next_pos,
  int length, int height
);

bool mouse_pos_is_good(
  vector<int> const (&mouse_field)[],
  unordered_map<Pos, Pos, HashPos>& came_from,
  unordered_map<Pos, pair<int, bool>, HashPos>& cost_so_far,
  MouseNode const (&current_node),
  Pos next_pos,
  int length, int height,
  bool& climbed
);