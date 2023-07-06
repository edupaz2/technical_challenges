#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

struct Cell
{
  Cell() = default;
  ~Cell() = default;
  Cell(const Cell& other) = default;

  Cell(int r, int c)
    : row(std::move(r)), col(std::move(c))
  {}

  Cell(Cell&& other)
    : row(std::move(other.row)), col(std::move(other.col))
  {}

  Cell& operator=(const Cell& other) = default;
  bool operator==(const Cell& other) const {
    return row == other.row && col == other.col;
  }

  friend ostream& operator<<(ostream& os, const Cell& c);

  int row{-1}, col{-1};
};

ostream& operator<<(ostream& os, const Cell& c)
{
  return os << "(" << c.row << "," << c.col << ")";
}

int manhattanDistance(Cell from, Cell to)
{
  return std::abs(from.row-to.row) + std::abs(from.col-to.col);
}

bool checkCellBoundaries(int row, int col, int max)
{
  return row >= 0 && col >= 0 && row < max && col < max;
}

int findClosestGoal(Cell startCell, std::vector<Cell> goals, int arrLength)
{
  std::list<Cell> toVisitCells;
  std::list<Cell> visited;
  toVisitCells.push_back(startCell);
  while(!toVisitCells.empty()) {
    auto current = toVisitCells.front();
    toVisitCells.pop_front();
    visited.push_back(current);
    auto it = std::find(goals.begin(), goals.end(), current);
    if(it != goals.end())
    {
      return it - goals.begin();
    }
    // check neighbours and add the new.
    if(checkCellBoundaries(current.row-1, current.col, arrLength)) {
      // Left cell
      Cell left{current.row-1, current.col};
      if(std::find(visited.begin(), visited.end(), left) == visited.end())
      {
        toVisitCells.insert(find_if(std::begin(toVisitCells), std::end(toVisitCells), [left, current](auto c){
          return manhattanDistance(left, current) > manhattanDistance(c, current);
        }), left);
      }
    }
    if(checkCellBoundaries(current.row, current.col-1, arrLength)) {
      // Up cell
      Cell up{current.row, current.col-1};
      if(std::find(visited.begin(), visited.end(), up) == visited.end())
      {
        toVisitCells.insert(find_if(std::begin(toVisitCells), std::end(toVisitCells), [up, current](auto c){
          return manhattanDistance(up, current) > manhattanDistance(c, current);
        }), up);
      }
    }
    if(checkCellBoundaries(current.row+1, current.col, arrLength)) {
      // Right cell
      Cell right{current.row+1, current.col};
      if(std::find(visited.begin(), visited.end(), right) == visited.end())
      {
        toVisitCells.insert(find_if(std::begin(toVisitCells), std::end(toVisitCells), [right, current](auto c){
          return manhattanDistance(right, current) > manhattanDistance(c, current);
        }), right);
      }
    }
    if(checkCellBoundaries(current.row, current.col+1, arrLength)) {
      // Down cell
      Cell down{current.row, current.col+1};
      if(std::find(visited.begin(), visited.end(), down) == visited.end())
      {
        toVisitCells.insert(find_if(std::begin(toVisitCells), std::end(toVisitCells), [down, current](auto c){
          return manhattanDistance(down, current) > manhattanDistance(c, current);
        }), down);
      }
    }
  }
  return -1;
}

int SearchingChallenge(string strArr[], int arrLength) {
  // code goes here
  int numberOfSteps = 0;
  Cell home, charlie;
  std::vector<Cell> food;
  for(int i=0; i<arrLength; ++i) {
    for(int j=0; j<arrLength; ++j) {
      if(strArr[i].at(j) == 'H') {
        home.row = i;
        home.col = j;
      } else if(strArr[i].at(j) == 'C') {
        charlie.row = i;
        charlie.col = j;
      } else if(strArr[i].at(j) == 'F') {
        food.emplace_back(i, j);
      }
    }
  }

  // Handle errors
  if(home.row == -1 || home.col == -1) {
    return numberOfSteps;
  }
  if(charlie.row == -1 || charlie.col == -1) {
    return numberOfSteps;
  }
  if(food.size() < 1 || food.size() > 8) {
    return numberOfSteps;
  }

  // Start in H, find the closest F until finish, then C
  Cell startCell = home;
  std::vector<Cell> goals = food;
  bool charlieAdded = false;
  while(!goals.empty()) {
    auto found = findClosestGoal(startCell, goals, arrLength);
    if(found != -1) {
      // If last one, add Charlie
      if(goals.size() == 1 && !charlieAdded)
      {
        goals.push_back(charlie);
        charlieAdded = true;
      }
      numberOfSteps += manhattanDistance(startCell, goals[found]);
      startCell = goals[found];
      goals.erase(goals.begin()+found);
    } else {
      return 0;
    }
  }

  return numberOfSteps;
}

int main(void) { 
  // Tests
  {
    string test[] = {"OOOO", "OOFF", "OCHO", "OFOO"};
    if(SearchingChallenge(test, 4) != 7)
    {
      cout << -1;
    }
    else
    {
      cout << "TEST PASSED" << std::endl;
    }
  }
  {
    string test[] = {"FOOF", "OCOO", "OOOH", "FOOO"};
    if(SearchingChallenge(test, 4) != 11)
    {
      cout << -1;
    }
    else
    {
      cout << "TEST PASSED" << std::endl;
    }
  }
  {
    string test[] = {"FOOO", "OCOH", "OFOF", "OFOO"};
    if(SearchingChallenge(test, 4) != 10)
    {
      cout << -1;
    }
    else
    {
      cout << "TEST PASSED" << std::endl;
    }
  }
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  int result =  SearchingChallenge(A, arrLength);
  cout << result;
  return 0;
    
}