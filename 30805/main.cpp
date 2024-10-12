#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> a;
int m;
vector<int> b;
int lcs[101][101];
deque<int> lcs_result;
vector<int> indexes[10];
vector<int> answer;
int maximum;

void print_answer() {
  cout << answer.size() << '\n';
  for (int i = 0; i < answer.size(); i++) {
    cout << answer[i] << ' ';
  }
  cout << '\n';
}

void generate_answer() {
  for (int i = 9; i >= 0; i--) {
    for (int j = 0; j < indexes[i].size(); j++) {
      if (indexes[i][j] < maximum) {
        continue;
      }
      maximum = indexes[i][j];
      answer.push_back(lcs_result[indexes[i][j]]);
    }
  }
}

void traverse() {
  for (int i = 0; i < lcs_result.size(); i++) {
    indexes[lcs_result[i]].push_back(i);
  }
}

void cal_lcs() {
  for (int j = 1; j <= b.size(); j++) {
    for (int i = 1; i <= a.size(); i++) {
      if (b[j - 1] == a[i - 1]) {
        lcs[j][i] = lcs[j - 1][i - 1] + 1;
      } else {
        lcs[j][i] = max(lcs[j - 1][i], lcs[j][i - 1]);
      }
    }
  }
}

void lcs_trace() {
  int j = b.size();
  int i = a.size();

  while (1) {
    if (lcs[j][i] == 0) {
      break;
    } else if (lcs[j][i] == lcs[j][i - 1]) {
      i -= 1;
    } else if (lcs[j][i] == lcs[j - 1][i]) {
      j -= 1;
    } else {
      lcs_result.push_front(a[i - 1]);
      i -= 1;
      j -= 1;
    }
  }
}

void sol() {
  cal_lcs();
  lcs_trace();
  traverse();
  generate_answer();
  print_answer();
}

int main() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> m;
  b.resize(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  sol();
}
