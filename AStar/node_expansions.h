#pragma once

#include <vector>
#include "structs.h"
#include <unordered_map>
#include <queue>

using std::priority_queue, std::vector, std::unordered_map, std::pair;

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

void expand_human_node(
  vector<int> const (&human_field)[],
  priority_queue<Node, vector<Node>, PrioritiseNode>& frontier,
  unordered_map<Pos, Pos, HashPos>& came_from,
  unordered_map<Pos, int, HashPos>& cost_so_far,
  Node const (&current_node),
  int length, int height
);

void expand_mouse_node(
  vector<int> const (&mouse_field)[],
  priority_queue<MouseNode, vector<MouseNode>, PrioritiseNode>& frontier,
  unordered_map<Pos, Pos, HashPos>& came_from,
  unordered_map<Pos, pair<int, bool>, HashPos>& cost_so_far,
  MouseNode const (&current_node),
  int length, int height
);