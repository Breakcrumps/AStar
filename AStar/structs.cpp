#include <iostream>
#include "structs.h"

using std::size_t;

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

bool Pos::operator==(Pos other) const
{
  return x == other.x and y == other.y;
}

Pos Pos::operator+(Pos other) const
{
  return { x + other.x, y + other.y };
}

/////////////////////////////////////////////////////////////////////////////////


size_t HashPos::operator()(Pos pos) const
{
  return
    pos.x >= pos.y
    ? (pos.x * pos.x) + pos.x + pos.y
    : pos.x + (pos.y * pos.y);
}

/////////////////////////////////////////////////////////////////////////////////


Node::Node(int heuristic, Pos pos, int turn)
{
  this->heuristic = heuristic;
  this->pos = pos;
  this->turn = turn;
}
Node::Node(int heuristic, Pos pos)
{
  this->heuristic = heuristic;
  this->pos = pos;
  this->turn = 0;
}

MouseNode::MouseNode(int heuristic, Pos pos)
{
  this->heuristic = heuristic;
  this->pos = pos;
  this->turn = 0;
  this->climbed = false;
}
MouseNode::MouseNode(int heuristic, Pos pos, int turn, bool climbed)
{
  this->heuristic = heuristic;
  this->pos = pos;
  this->turn = turn;
  this->climbed = climbed;
}

/////////////////////////////////////////////////////////////////////////////////

bool PrioritiseNode::operator()(Node first, Node second) const
{
  return first.heuristic > second.heuristic;
}
bool PrioritiseNode::operator()(MouseNode first, MouseNode second) const
{
  return first.heuristic > second.heuristic;
}