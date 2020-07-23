#include <iostream>
#include <limits.h>

using namespace std;

int main(int argc, char **argv)
{
  // Get the size of the sequence
  auto n = 1;
  int *p;

  cin >> n;

  p = new int[n + 1];
  p[0] = 0;

  for (auto i = 1; i <= n; i++)
  {
    cin >> p[i];
  }

  auto output = [&]() { // Extended Bottom Up Cut Rod
    auto *r = new int[n + 1];
    auto *s = new int[n + 1];
    int q;

    r[0] = 0;

    for (auto i = 1; i <= n; i++)
    {
      q = INT_MIN;
      for (int j = 1; j <= i; j++)
      {
        if (q < p[j] + r[i - j])
        {
          q = p[j] + r[i - j];
          s[i] = j;
        }
      }
      r[i] = q;
    }

    auto result = [&]() { // Print Cut Rod Solution
      cout << r[n] << endl;
      while (n > 0)
      {
        cout << s[n] << " ";
        n -= s[n];
      }
      cout << "-1" << endl;
    };

    result();
  };

  output();

  // Free allocated space
  delete[] p;

  return 1;
}
