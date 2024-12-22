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
)
{
  if (not pos_exists(next_pos, length, height))
    return false;
  if (pos_is_a_wall(human_field, next_pos))
    return false;

  if (came_from[current_node.pos] == next_pos)
    return false;
  if (
    cost_so_far.find(next_pos) != cost_so_far.end()
    and cost_so_far[next_pos] < current_node.turn + 1
  )
    return false;

  return true;
}

/////////////////////////////////////////////////////////////////////////////////

bool human_second_pos_is_good(
  vector<int> const (&human_field)[],
  Pos next_pos,
  int length, int height
)
{
  return
    pos_exists(next_pos, length, height)
    and not pos_is_a_wall(human_field, next_pos);
}

/////////////////////////////////////////////////////////////////////////////////

bool mouse_pos_is_good(
  vector<int> const (&mouse_field)[],
  unordered_map<Pos, Pos, HashPos>& came_from,
  unordered_map<Pos, pair<int, bool>, HashPos>& cost_so_far,
  MouseNode const (&current_node),
  Pos next_pos,
  int length, int height,
  bool& climbed
)
{
  if (not pos_exists(next_pos, length, height))
    return false;
  if (pos_is_a_wall(mouse_field, next_pos))
  {
    if (climbed)
      return false;
      
    climbed = true;
  }

  if (came_from[current_node.pos] == next_pos)
    return false;
  if (
    cost_so_far.find(next_pos) != cost_so_far.end()
    and cost_so_far[next_pos].first < current_node.turn + 1
    and cost_so_far[next_pos].second <= climbed
  )
    return false;

  return true;
}