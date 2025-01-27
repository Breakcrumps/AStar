#include <vector>
#include "structs.h"
#include <unordered_map>
#include <queue>
#include <math.h>
#include "common_funcs.h"
#include "position_checks.h"
#include "node_expansions.h"

using std::priority_queue, std::vector, std::unordered_map;

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

Pos moves[4] { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

/////////////////////////////////////////////////////////////////////////////////

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
    Pos next_pos = current_node.pos + move;

    if (not human_pos_is_good(human_field, came_from, cost_so_far, current_node, next_pos, length, height))
      continue;

    Node next_node(
      human_field[next_pos.y][next_pos.x],
      next_pos,
      current_node.turn + 1
    );

    frontier.push(next_node);
    came_from[next_node.pos] = current_node.pos;
    cost_so_far[next_node.pos] = next_node.turn;

    Pos second_next_pos = next_node.pos + move;

    if (not human_second_pos_is_good(human_field, second_next_pos, length, height))
      continue;

    Node second_next(
      human_field[second_next_pos.y][second_next_pos.x],
      second_next_pos,
      current_node.turn + 1
    );

    frontier.push(second_next);
    came_from[second_next.pos] = next_node.pos;
    cost_so_far[second_next.pos] = second_next.turn;
  }
}

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
    Pos next_pos = current_node.pos + move;

    bool climbed = current_node.climbed;

    if (not mouse_pos_is_good(mouse_field, came_from, cost_so_far, current_node, next_pos, length, height, climbed))
      continue;

    MouseNode next_node
    (
      abs(mouse_field[next_pos.y][next_pos.x]),
      next_pos,
      current_node.turn + 1,
      climbed
    );

    frontier.push(next_node);
    came_from[next_node.pos] = current_node.pos;
    cost_so_far[next_node.pos] = { next_node.turn, next_node.climbed };
  }
}