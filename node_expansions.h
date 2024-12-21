#pragma once

#include <vector>
#include "structs.h"
#include <unordered_map>
#include <queue>
#include "common_funcs.h"
#include "position_checks.h"

using std::priority_queue, std::vector, std::unordered_map;

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

Pos moves[4] { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

void expand_human_node(
  vector<int> const (&human_field)[],
  priority_queue<Node, vector<Node>, PrioritiseNode>& frontier,
  unordered_map<Pos, Pos, HashPos>& came_from,
  unordered_map<Pos, int, HashPos>& cost_so_far,
  Node const (&current_node),
  int length, int height
)
{
  for (Pos move : moves)
  {
    if (not human_pos_is_good(human_field, came_from, cost_so_far, current_node, move, length, height))
    {
      continue;
    }

    Node next_node(
      human_field[current_node.pos.y + move.y][current_node.pos.x + move.x],
      { current_node.pos.x + move.x, current_node.pos.y + move.y },
      current_node.turn+1
    );

    frontier.push(next_node);
    came_from[next_node.pos] = current_node.pos;
    cost_so_far[next_node.pos] = next_node.turn;

    if (not human_second_pos_is_good(human_field, next_node, move, length, height))
    {
      continue;
    }

    Node second_next(
      human_field[current_node.pos.y + move.y*2][current_node.pos.x + move.x*2],
      { current_node.pos.x + move.x*2, current_node.pos.y + move.y*2 },
      current_node.turn+1
    );

    frontier.push(second_next);
    came_from[second_next.pos] = next_node.pos;
    cost_so_far[second_next.pos] = second_next.turn;
  }
}

/////////////////////////////////////////////////////////////////////////////////

void expand_mouse_node(
  vector<int> const (&mouse_field)[],
  priority_queue<MouseNode, vector<MouseNode>, PrioritiseNode>& frontier,
  unordered_map<Pos, Pos, HashPos>& came_from,
  unordered_map<Pos, pair<int, bool>, HashPos>& cost_so_far,
  MouseNode const (&current_node),
  int length, int height
)
{
  for (Pos move : moves)
  {
    bool climbed = current_node.climbed;

    if (not mouse_pos_is_good(mouse_field, came_from, cost_so_far, current_node, move, length, height, climbed))
    {
      continue;
    }

    MouseNode next
    (
      abs(mouse_field[current_node.pos.y + move.y][current_node.pos.x + move.x]),
      { current_node.pos.x + move.x, current_node.pos.y + move.y },
      current_node.turn+1,
      climbed
    );

    frontier.push(next);
    came_from[next.pos] = current_node.pos;
    cost_so_far[next.pos] = { next.turn, next.climbed };
  }
}