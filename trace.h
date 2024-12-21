#pragma once

#include <queue>
#include <unordered_map>
#include <vector>
#include "structs.h"

using std::vector, std::unordered_map, std::priority_queue, std::string;

void trace_human_thinking_tick(
  priority_queue<Node, vector<Node>, PrioritiseNode> frontier,
  string& trace,
  unordered_map<Pos, Pos, HashPos>& came_from
)
{
  while (not frontier.empty())
  {
    Node current = frontier.top();
    trace += current.pos.x + current.pos.y + ' ' + current.turn + ' ' + current.heuristic + ' ';
    trace += came_from[{current.pos.x, current.pos.y}].x + came_from[{current.pos.x, current.pos.y}].y;
    trace += '\n';
    frontier.pop();
  }

  trace += '\n';
}