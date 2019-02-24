#include <iostream>

#define MAX_INT 2147483647

using namespace std;
  
int maxCrossingSubarray(int* seq, int low, int mid, int high) {
  int leftSum = -MAX_INT, rightSum = -MAX_INT;
  for (int i = mid, sum = 0; i >= low; i--) {
    sum = sum + seq[i];
    if (sum > leftSum)
      leftSum = sum;
  }
  for (int j = mid + 1, sum = 0; j <= high; j++) {
    sum = sum + seq[j];
    if (sum > rightSum)
      rightSum = sum;
  }
  return leftSum + rightSum;
}

int maxSubarray(int* seq, int low, int high) {
  if (high == low) {
    return seq[low]; // base case: only one element
  } else {
    int mid = (low + high) / 2;
    int leftSum = maxSubarray(seq, low, mid);
    int rightSum = maxSubarray(seq, mid + 1, high);
    auto crossSum = [&]() {
      int leftSum = -MAX_INT, rightSum = -MAX_INT;
      for (int i = mid, sum = 0; i >= low; i--) {
        sum = sum + seq[i];
        if (sum > leftSum)
          leftSum = sum;
      }
      for (int j = mid + 1, sum = 0; j <= high; j++) {
        sum = sum + seq[j];
        if (sum > rightSum)
          rightSum = sum;
      }
      return leftSum + rightSum;
    };
    
    if (leftSum >= rightSum and leftSum >= crossSum())
      return leftSum;
    else if (rightSum >= leftSum and rightSum >= crossSum())
      return rightSum;
    else 
      return crossSum();
  }
}

int main(int argc, char **argv) {

  int* Sequence;
  int arraySize = 1;

  // Get the size of the sequence
  cin >> arraySize;
  Sequence = new int[arraySize];
    
  // Read the sequence
  for(int i = 0; i < arraySize; i++)
    cin >> Sequence[i];

  cout << maxSubarray(Sequence, 0, arraySize - 1);

  // Free allocated space
  delete[] Sequence;
}
