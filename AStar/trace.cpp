#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
#include "structs.h"
#include "trace.h"

using std::vector, std::unordered_map, std::priority_queue, std::string;

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

string trace_human_thinking_tick(
  priority_queue<Node, vector<Node>, PrioritiseNode> frontier,
  unordered_map<Pos, Pos, HashPos>& came_from
)
{
  string trace;

  while (not frontier.empty())
  {
    Node current = frontier.top();
    trace += current.pos.x + current.pos.y + ' ' + current.turn + ' ' + current.heuristic + ' ';
    trace += came_from[{current.pos.x, current.pos.y}].x + came_from[{current.pos.x, current.pos.y}].y;
    trace += '\n';
    frontier.pop();
  }

  trace += '\n';

  return trace;
}

string trace_mouse_thinking_tick(
  priority_queue<MouseNode, vector<MouseNode>, PrioritiseNode> frontier,
  unordered_map<Pos, Pos, HashPos>& came_from
)
{
  string trace;

  while (not frontier.empty())
  {
    MouseNode current = frontier.top();
    trace += current.pos.x + current.pos.y + ' ' + current.turn + ' ' + current.heuristic + ' ';
    trace += came_from[current.pos].x + came_from[current.pos].y + ' ';
    trace += current.climbed;
    trace += '\n';
    frontier.pop();
  }
  
  trace += '\n';

  return trace;
}