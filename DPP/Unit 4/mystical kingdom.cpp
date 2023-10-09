#include <iostream>

using namespace std;

int tower_of_hanoi(int n, int source_peg, int destination_peg, int helper_peg) {
  if (n == 1) {
    return 1;
  }

  int moves = tower_of_hanoi(n - 1, source_peg, helper_peg, destination_peg);

  moves += 1;

  moves += tower_of_hanoi(n - 1, helper_peg, destination_peg, source_peg);

  return moves;
}

int main() {
  int n;
  cout << "Enter the number of disks: ";
  cin >> n;

  if (n < 1 || n > 8) {
    cout << "The number of disks must be between 1 and 8." << endl;
    return 1;
  }

  int minimum_moves = tower_of_hanoi(n, 0, 2, 1);

  cout << "The minimum number of moves required to solve the Tower of Hanoi problem for " << n << " magical disks is " << minimum_moves << endl;

  return 0;
}
