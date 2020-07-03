#include <iostream>

#define MAX_INT 2147483647

using namespace std;

int maxSubarray(int *seq, int low, int high)
{
  if (high == low)
  {
    return seq[low]; // base case: only one element
  }
  else
  {
    auto mid = (low + high) / 2;
    auto leftSum = maxSubarray(seq, low, mid);
    auto rightSum = maxSubarray(seq, mid + 1, high);

    auto crossSum = [&]() {
      auto leftSum = -MAX_INT, rightSum = -MAX_INT;

      for (auto i = mid, sum = 0; i >= low; i--)
      {
        sum = sum + seq[i];

        if (sum > leftSum)
          leftSum = sum;
      }

      for (auto j = mid + 1, sum = 0; j <= high; j++)
      {
        sum = sum + seq[j];

        if (sum > rightSum)
          rightSum = sum;
      }

      return leftSum + rightSum;
    };

    return (leftSum >= rightSum & leftSum >= crossSum()) ? leftSum : ((rightSum >= leftSum & rightSum >= crossSum()) ? rightSum : crossSum());
  }
}

int main(int argc, char **argv)
{

  int *Sequence;
  auto arraySize = 1;

  // Get the size of the sequence
  cin >> arraySize;
  Sequence = new int[arraySize];

  // Read the sequence
  for (auto i = 0; i < arraySize; i++)
    cin >> Sequence[i];

  cout << maxSubarray(Sequence, 0, arraySize - 1);

  // Free allocated space
  delete[] Sequence;
}
