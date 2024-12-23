#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
#include "structs.h"
#include "parent_funcs.h"
#include "funcs_for_main.h"

using std::vector, std::string, std::cin, std::cout, std::ostringstream;

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

int main()
{
  int height, length;
  cin >> height >> length;
  cin.ignore();

  Pos human_pos, mouse_pos, finish_pos;
  string field[height];

  for (int line_index = 0; line_index < height; ++line_index)
  {
    string line;
    getline(cin, line);
    
    line.erase(remove(line.begin(), line.end(), ' '), line.end());

    field[line_index] = line;

    if (line.find('H') != -1)
    {
      human_pos.x = line.find('H');
      human_pos.y = line_index;
    }
    if (line.find('M') != -1)
    {
      mouse_pos.x = line.find('M');
      mouse_pos.y = line_index;
    }
    if (line.find('F') != -1)
    {
      finish_pos.x = line.find('F');
      finish_pos.y = line_index;
    }
  }

  vector<int> human_field[height];

  fill_human_field(
    field,
    finish_pos,
    height, length,
    human_field
  );

  cout << '\n';

  cout << format_field(human_field, height);

  // double start_time = clock() / CLOCKS_PER_SEC;

  int human_moves = human_function(
    human_pos,
    human_field,
    (height * length) - 1,
    height,
    length
  );

  cout << human_moves << "\n\n";

  // cout << (double)(clock() / CLOCKS_PER_SEC) - start_time << endl;

  vector<int> mouse_field[height];

  fill_mouse_field(field, finish_pos, height, length, mouse_field);

  cout << format_field(mouse_field, height);

  int mouse_moves = mouse_function(
    mouse_pos,
    mouse_field,
    (height * length) - 1,
    height, length
  );

  cout << mouse_moves << "\n\n";
  
  cout << results(human_moves, mouse_moves);

  return 0;
}