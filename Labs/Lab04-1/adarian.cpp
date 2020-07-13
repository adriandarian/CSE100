#include <iostream>

#define MAX_INT 2147483647

using namespace std;

/**
 * MaxHeapify
 * 
 * @param seq array of elements
 * @param i starting point
 * @param size length of array
*/
void MaxHeapify(int *seq, int i, int size)
{
  int largest;

  /**
   * l
   * 
   * @param i 
   * 
   * @return 2 times i
  */
  auto l = [&i]() {
    return 2 * i;
  };

  /**
   * r
   * 
   * @param i 
   * 
   * @return (1 plus i) times 2
  */
  auto r = [&i]() {
    return 2 * i + 1;
  };

  if (l() < size and seq[l()] > seq[i])
    largest = l();
  else
    largest = i;

  if (r() < size and seq[r()] > seq[largest])
    largest = r();

  if (largest != i)
  {
    seq[largest] = seq[largest] ^ seq[i];
    seq[i] = seq[largest] ^ seq[i];
    seq[largest] = seq[largest] ^ seq[i];
    MaxHeapify(seq, largest, size);
  }
}

/**
 * HeapSort
 * 
 * @param seq array of elements to be sorted
 * @param size length of array
*/
void HeapSort(int *seq, int size)
{
  /**
   * BuildMaxHeap
   * 
   * @param seq array sequence
   * @param size size of array
   * 
   * Loops through and calls MaxHeapify on different subarrays
  */
  auto BuildMaxHeap = [seq, size]() {
    for (int i = (size / 2) - 1; i >= 0; i--)
      MaxHeapify(seq, i, size);
  };

  // Generates a Max Heap
  BuildMaxHeap();

  // loops through and swaps each value then calls a MaxHeapify on the new subarray
  for (auto i = size - 1; i >= 0; i--)
  {
    swap(seq[0], seq[i]);
    size--;
    MaxHeapify(seq, 0, size);
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

  // Runs HeapSort algoritm on sequence
  HeapSort(Sequence, arraySize);

  // Print out each element in sorted array
  for (auto c = 0; c < arraySize; c++)
    cout << Sequence[c] << ';';

  // Free allocated space
  delete[] Sequence;
}
