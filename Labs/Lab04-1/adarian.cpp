#include <iostream>

#define MAX_INT 2147483647

using namespace std;

void MaxHeapify(int* seq, int i, int size) {
  int largest;
  auto l = [&i]() {
    return 2 * i;
  };
  auto r = [&i]() {
    return 2 * i + 1;
  };

  if (l() < size and seq[l()] > seq[i])
    largest = l();
  else
    largest = i;
  if (r() < size and seq[r()] > seq[largest])
    largest = r();
  if (largest != i) {
    seq[largest] = seq[largest] ^ seq[i];
    seq[i] = seq[largest] ^ seq[i];
    seq[largest] = seq[largest] ^ seq[i];
    MaxHeapify(seq, largest, size);
  }
}

void HeapSort(int* seq, int size) {
  auto BuildMaxHeap = [seq, size]() {
    for (int i = (size / 2) - 1; i >= 0; i--) {
      MaxHeapify(seq, i, size);
    }
  };
  BuildMaxHeap();
  for (int i = size-1; i >= 0; i--) {
    swap(seq[0], seq[i]);
    size -= 1;
    MaxHeapify(seq, 0, size);
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

  HeapSort(Sequence, arraySize);

  for (int c = 0; c < arraySize; c++) {
    cout << Sequence[c] << ';';
  }

  // Free allocated space
  delete[] Sequence;
}
