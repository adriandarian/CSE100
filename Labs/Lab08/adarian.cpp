#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include<limits.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

void MatrixChainOrder(int p[], vector<vector<int>> &m, vector<vector<int>> &s) {
  for (auto i = 1; i < m.size(); i++) {
    m[i][i] = 0;
  }

  for (auto l = 2; l < m.size(); l++) {
    for (auto i = 1; i < m.size() - l + 1; i++) {
      auto j = i + l - 1;
      m[i][j] = INT_MAX;
      for (auto k = i; k <= j - 1; k++) {
        auto q = m[i][k] + m[k + 1][j] + (p[i - 1] * p[k] * p[j]);
        if (q < m[i][j]) {
          m[i][j] = q;
          s[i][j] = k;
        }
      }
    }
  }
}

void PrintOptimalParens(vector<vector<int>> s, int i, int j) {
  if (i == j) {
    cout << "A" << (i - 1);
  } else {
    cout << "(";
    PrintOptimalParens(s, i, s[i][j]);
    PrintOptimalParens(s, s[i][j] + 1, j);
    cout << ")";
  }
}

int main() {
  int len;
  cin >> len;
  int values[len];

  for (int i = 0; i <= len; i++) {
    cin >> values[i];
  }

  vector<vector<int>> m(len + 1, vector<int>(len + 1, 0));
  vector<vector<int>> s(len + 1, vector<int>(len + 1, 0));

  MatrixChainOrder(values, m, s);

  cout << m[1][len] << "\n";
  PrintOptimalParens(s, 1, len);
  cout << "\n";

  return 0;
}