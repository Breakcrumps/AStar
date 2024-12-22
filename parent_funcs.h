#pragma once

#include "structs.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include "common_funcs.h"
#include "node_expansions.h"

using std::vector, std::priority_queue, std::unordered_map;

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
    // trace_human_nodes(frontier, trace, came_from);

    Node current_node = frontier.top();
    frontier.pop();

    if (reached_the_finish(current_node) and current_node.turn < winner)
    {
      winner = current_node.turn;
    }

    if (current_node.turn > winner or current_node.turn > max_turns)
    {
      continue;
    }

    expand_human_node(human_field, frontier, came_from, cost_so_far, current_node, length, height);
  }

  // ofstream tracefile("trace.txt");
  // tracefile << trace;
  // tracefile.close();

  return winner;
}

/////////////////////////////////////////////////////////////////////////////////

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

  unordered_map<Pos, pair<int, bool>, HashPos> cost_so_far { {start_pos, {0, 0}} };

  int winner = 999999;

  while (not frontier.empty())
  {
    // priority_queue<MouseNode, vector<MouseNode>, PrioritiseNode> test_frontier(frontier);
    // while (not test_frontier.empty())
    // {
    //   MouseNode current = test_frontier.top();
    //   trace += current.pos.x + current.pos.y + ' ' + current.turn + ' ' + current.heuristic + ' ';
    //   trace += came_from[{current.pos.x, current.pos.y}].x + came_from[{current.pos.x, current.pos.y}].y + ' ';
    //   trace += current.climbed;
    //   trace += '\n';
    //   test_frontier.pop();
    // }
    // trace += '\n';

    MouseNode current_node = frontier.top();
    frontier.pop();

    if (reached_the_finish(current_node) and current_node.turn < winner)
    {
      winner = current_node.turn;
    }

    if (current_node.turn > winner or current_node.turn > max_turns)
    {
      continue;
    }

    expand_mouse_node(mouse_field, frontier, came_from, cost_so_far, current_node, length, height);
  }

  // ofstream tracefile("mouse_trace.txt");
  // tracefile << trace;
  // tracefile.close();

  return winner;
}