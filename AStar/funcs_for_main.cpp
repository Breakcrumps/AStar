#include <sstream>
#include <vector>
#include "structs.h"
#include "funcs_for_main.h"

using std::ostringstream, std::vector, std::string;

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

string results(int human_moves, int mouse_moves)
{
  if (human_moves > mouse_moves)
    return "MOUSE\n";

  if (human_moves < mouse_moves)
    return "HUMAN\n";

  return "DRAW\n";
}

/////////////////////////////////////////////////////////////////////////////////

string format_field(vector<int> const (&field)[], int height)
{
  ostringstream formatted_field;

  for (int i = 0; i < height; ++i)
  {
    for (int s : field[i])
    {
      formatted_field << s << ' ';
    }

    formatted_field << '\n';
  }
  
  formatted_field << '\n';

  return formatted_field.str();
}

/////////////////////////////////////////////////////////////////////////////////

void fill_human_field(
  string const (&field)[],
  Pos finish_pos,
  int height, int length,
  vector<int> (&human_field)[]
)
{
  for (int y = 0; y < height; ++y)
  {
    for (int x = 0; x < length; ++x)
    {
      human_field[y].push_back(
        field[y][x] != 'W'
        ? (int)((abs(finish_pos.y - y) + 1) / 2)
        + (int)((abs(finish_pos.x - x) + 1) / 2)
        : -1
      );
    }
  }
}

void fill_mouse_field(
  string const (&field)[],
  Pos finish_pos,
  int height, int length,
  vector<int> (&mouse_field)[]
)
{
  for (int y = 0; y < height; ++y)
  {
    for (int x = 0; x < length; ++x)
    {
      mouse_field[y].push_back(
        field[y][x] != 'W'
        ? abs(finish_pos.y - y) + abs(finish_pos.x - x)
        : -(abs(finish_pos.y - y) + abs(finish_pos.x - x))
      );
    }
  }
}