#include <vector>
#include <queue>
#include <unordered_map>
#include <fstream>
#include "common_funcs.h"
#include "node_expansions.h"
#include "trace.h"
#include "structs.h"
#include "parent_funcs.h"

using std::vector, std::priority_queue, std::unordered_map, std::ofstream;

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

int human_function(
  Pos start_pos,
  vector<int> const (&human_field)[],
  int max_turns,
  int height,
  int length
)
{
  // string trace;

  priority_queue<Node, vector<Node>, PrioritiseNode> frontier;

  Node first_node(human_field[start_pos.y][start_pos.x], start_pos);

  frontier.push(first_node);

  unordered_map<Pos, Pos, HashPos> came_from { {start_pos, start_pos} };

  unordered_map<Pos, int, HashPos> cost_so_far { {start_pos, 0} };

  int winner = 999999;

  while (not frontier.empty())
  {
    // trace += trace_human_thinking_tick(frontier, came_from);

    Node current_node = frontier.top();
    frontier.pop();

    if (reached_the_finish(current_node) and current_node.turn < winner)
      winner = current_node.turn;

    if (current_node.turn > winner or current_node.turn > max_turns)
      continue;

    expand_human_node(human_field, frontier, came_from, cost_so_far, current_node, length, height);
  }

  // ofstream tracefile("trace.txt");
  // tracefile << trace;
  // tracefile.close();

  return winner;
}

int mouse_function(
  Pos start_pos,
  vector<int> const (&mouse_field)[],
  int max_turns,
  int height,
  int length
)
{
  // string trace;

  priority_queue<MouseNode, vector<MouseNode>, PrioritiseNode> frontier;

  MouseNode first_node(mouse_field[start_pos.y][start_pos.x], start_pos);

  frontier.push(first_node);

  unordered_map<Pos, Pos, HashPos> came_from { {start_pos, start_pos} };

  unordered_map<Pos, pair<int, bool>, HashPos> cost_so_far { {start_pos, {0, false}} };

  int winner = 999999;

  while (not frontier.empty())
  {
    // trace += trace_mouse_thinking_tick(frontier, came_from);

    MouseNode current_node = frontier.top();
    frontier.pop();

    if (reached_the_finish(current_node) and current_node.turn < winner)
      winner = current_node.turn;

    if (current_node.turn > winner or current_node.turn > max_turns)
      continue;

    expand_mouse_node(mouse_field, frontier, came_from, cost_so_far, current_node, length, height);
  }

  // ofstream tracefile("mouse_trace.txt");
  // tracefile << trace;
  // tracefile.close();

  return winner;
}