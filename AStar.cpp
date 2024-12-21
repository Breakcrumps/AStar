#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <time.h>
#include <unordered_map>
#include <fstream>
#include "structs.h"
#include "parent_funcs.h"

using std::vector, std::string, std::cin, std::cout;

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

int main()
{
  int height, length;
  cin >> height >> length;
  cin.ignore();

  Pos human_location, mouse_location, finish_location;
  string field[height];

  for (int line_index = 0; line_index < height; ++line_index)
  {
    string line;
    getline(cin, line);
    
    line.erase(remove(line.begin(), line.end(), ' '), line.end());

    field[line_index] = line;

    if (line.find('H') != -1)
    {
      human_location.x = line.find('H');
      human_location.y = line_index;
    }
    if (line.find('M') != -1)
    {
      mouse_location.x = line.find('M');
      mouse_location.y = line_index;
    }
    if (line.find('F') != -1)
    {
      finish_location.x = line.find('F');
      finish_location.y = line_index;
    }
  }

  vector<int> human_field[height];

  for (int y = 0; y < height; ++y)
  {
    for (int x = 0; x < length; ++x)
    {
      human_field[y].push_back(
        field[y][x] != 'W'
        ? (int)((abs(finish_location.y - y) + 1) / 2) + (int)((abs(finish_location.x - x) + 1) / 2)
        : -1
      );
    }
  }

  cout << '\n';

  for (vector<int> i : human_field)
  {
    for (int s : i)
    {
      cout << s << ' ';
    }
    cout << '\n';
  }
  cout << '\n';

  // double start_time = clock() / CLOCKS_PER_SEC;

  int human_moves = human_function(
    human_location,
    human_field,
    (height * length) - 1,
    height,
    length
  );

  cout << human_moves << "\n\n";

  // cout << (double)(clock() / CLOCKS_PER_SEC) - start_time << endl;

  vector<int> mouse_field[height];

  for (int y = 0; y < height; ++y)
  {
    for (int x = 0; x < length; ++x)
    {
      mouse_field[y].push_back
      (
        field[y][x] != 'W'
        ? abs(finish_location.y - y) + abs(finish_location.x - x)
        : -(abs(finish_location.y - y) + abs(finish_location.x - x))
      );
    }
  }

  for (vector<int> i : mouse_field)
  {
    for (int s : i)
    {
      cout << s << ' ';
    }
    cout << '\n';
  }
  cout << '\n';

  int mouse_moves = mouse_function(mouse_location, mouse_field, (height * length) - 1, height, length);

  cout << mouse_moves << "\n\n";
  
  if (human_moves > mouse_moves)
  {
    cout << "MOUSE\n";
  }
  else if (human_moves < mouse_moves)
  {
    cout << "HUMAN\n";
  }
  else
  {
    cout << "DRAW\n";
  }

  return 0;
}