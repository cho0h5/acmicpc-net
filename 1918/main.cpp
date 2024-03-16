#include <cctype>
#include <iostream>
#include <map>
#include <stack>

using namespace std;

stack<char> s;
string result;

map<char, int> isp;
map<char, int> osp;

void handle(char c) {
  if (c == ')') {
    while (1) {
      char a = s.top();
      s.pop();
      if (a == '(')
        return;
      result.push_back(a);
    }
  }
  if (s.empty()) {
    s.push(c);
    return;
  }
  if (isp[s.top()] < osp[c])
    s.push(c);
  else {
    while (s.size() && isp[s.top()] >= osp[c]) {
      result.push_back(s.top());
      s.pop();
    }
    s.push(c);
  }
}

int main() {
  isp.insert({'(', 0});
  isp.insert({'+', 1});
  isp.insert({'-', 1});
  isp.insert({'*', 2});
  isp.insert({'/', 2});

  osp.insert({'(', 4});
  osp.insert({'+', 1});
  osp.insert({'-', 1});
  osp.insert({'*', 2});
  osp.insert({'/', 2});

  string input;
  cin >> input;

  for (int i = 0; i < input.size(); i++) {
    if (!isalpha(input[i]))
      handle(input[i]);
    else
      result.push_back(input[i]);
  }
  while (s.size()) {
    result.push_back(s.top());
    s.pop();
  }
  cout << result << '\n';
}
