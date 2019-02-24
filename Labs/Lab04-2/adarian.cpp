#include <iostream>

#define MAX_INT 2147483647

using namespace std;

auto Partition(int* seq, int p, int r) {
  int x = seq[r];
  int i = p - 1;
  for (int j = p; j < r - 1; j++) {
    if (seq[j] <= x) {
      i += 1;
      swap(seq[i], seq[j]);
    }
  }
  swap(seq[i + 1], seq[r]);
  return i + 1;
}

void QuickSort(int* seq, int p, int r) {
  if (p < r) {
    auto q = Partition(seq, p, r);
    QuickSort(seq, p, q - 1);
    QuickSort(seq, q + 1, r);
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

  QuickSort(Sequence, 0, arraySize);

  for (int c = 0; c < arraySize; c++) {
    cout << Sequence[c] << ';';
  }

  // Free allocated space
  delete[] Sequence;
}
