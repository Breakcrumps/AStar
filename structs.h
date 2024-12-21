#pragma once

#include <iostream>

using std::size_t;

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

struct Pos
{
  int x;
  int y;

  bool operator==(Pos other) const
  {
    return x == other.x and y == other.y;
  }
};

/////////////////////////////////////////////////////////////////////////////////

struct HashPos
{
  size_t operator() (Pos pos) const
  {
    return
      pos.x >= pos.y
      ? (pos.x * pos.x) + pos.x + pos.y
      : pos.x + (pos.y * pos.y);
  }
};

/////////////////////////////////////////////////////////////////////////////////

struct Node
{
  int heuristic;
  Pos pos;
  int turn;

  Node(int heuristic, Pos pos, int turn)
  {
    this->heuristic = heuristic;
    this->pos = pos;
    this->turn = turn;
  }
  Node(int heuristic, Pos pos)
  {
    this->heuristic = heuristic;
    this->pos = pos;
    this->turn = 0;
  }
};

/////////////////////////////////////////////////////////////////////////////////

struct MouseNode
{
  int heuristic;
  Pos pos;
  int turn;
  bool climbed;
  
  MouseNode(int heuristic, Pos pos)
  {
    this->heuristic = heuristic;
    this->pos = pos;
    this->turn = 0;
    this->climbed = false;
  }
  MouseNode(int heuristic, Pos pos, int turn, bool climbed)
  {
    this->heuristic = heuristic;
    this->pos = pos;
    this->turn = turn;
    this->climbed = climbed;
  }
};

/////////////////////////////////////////////////////////////////////////////////

struct PrioritiseNode
{
  bool operator()(Node first, Node second) const
  {
    return first.heuristic > second.heuristic;
  }
  bool operator()(MouseNode first, MouseNode second) const
  {
    return first.heuristic > second.heuristic;
  }
};