#pragma once

#include "structs.h"
#include <vector>

using std::vector;

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

bool reached_the_finish(
  Node const (&current_node)
)
{
  return current_node.heuristic == 0;
}

bool reached_the_finish(
  MouseNode const (&current_node)
)
{
  return current_node.heuristic == 0;
}

/////////////////////////////////////////////////////////////////////////////////

bool pos_exists(
  Pos current,
  Pos move,
  int length, int height
)
{
  return
    current.x + move.x >= 0 and current.x + move.x < length
    and current.y + move.y >= 0 and current.y + move.y < height;
}

/////////////////////////////////////////////////////////////////////////////////

bool pos_is_a_wall(
  vector<int> const (&field)[],
  Pos current,
  Pos move
)
{
  return field [current.y + move.y] [current.x + move.x] < 0;
}