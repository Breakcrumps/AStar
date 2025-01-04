#pragma once

#include <queue>
#include <unordered_map>
#include <vector>
#include "structs.h"

using std::vector, std::unordered_map, std::priority_queue, std::string;

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

string trace_human_thinking_tick(
  priority_queue<Node, vector<Node>, PrioritiseNode> frontier,
  unordered_map<Pos, Pos, HashPos>& came_from
);

string trace_mouse_thinking_tick(
  priority_queue<MouseNode, vector<MouseNode>, PrioritiseNode> frontier,
  unordered_map<Pos, Pos, HashPos>& came_from
);