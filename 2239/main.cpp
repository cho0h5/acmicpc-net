#include <iostream>

using namespace std;

int get(int i, int j);

int board[9][9];

void print_board() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      // cout << board[i][j] << ' ';
      cout << get(i, j) << ' ';
    }
    cout << '\n';
  }
  cout << '\n';
}

int get(int i, int j) {
  if (board[i][j] >= 0) {
    return board[i][j];
  }
  return board[i][j] + 10;
}

int check(int i, int j) {
  print_board();
  for (int p = 0; p < 9; p++) {
    if (i != p && get(i, j) == get(p, j)) {
      cout << "out1\n";
      return 0;
    }
  }
  for (int q = 0; q < 9; q++) {
    if (j != q && get(i, j) == get(i, q)) {
      cout << "out2\n";
      return 0;
    }
  }

  // 0 1 2 3 4 5 6 7 8
  // 0 0 0 1 1 1 2 2 2
  int ii = i / 3;
  int jj = j / 3;

  for (int p = 0; p < 3; p++) {
    for (int q = 0; q < 3; q++) {
      int newi = ii * 3 + p;
      int newj = jj * 3 + q;
      if ((newi != i || newj != j) && get(newi, newj) == get(i, j)) {
        cout << "out3\n";
        return 0;
      }
    }
  }

  return 1;
}

void backtracking(const int pos) {
  if (pos > 80)
    print_board();
  const int i = pos / 9;
  const int j = pos % 9;
  if (board[i][j] > 0) {
    if (pos >= 80)
      return;
    backtracking(pos + 1);
    return;
  }

  for (int k = 0; k < 9; k++) {
    board[i][j] = k - 9;
    if (check(i, j))
      backtracking(pos + 1);
  }
  board[i][j] = 0;
}

int main() {
  for (int i = 0; i < 9; i++) {
    string line;
    cin >> line;
    for (int j = 0; j < line.size(); j++) {
      board[i][j] = line[j] - '0';
    }
  }

  print_board();
  backtracking(0);
  print_board();
}
