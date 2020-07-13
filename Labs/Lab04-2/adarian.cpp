#include <iostream>

#define MAX_INT 2147483647

using namespace std;

/**
 * RandomizedPartition
 * 
 * @param seq array of elements to be sorted
 * @param p left most
 * @param r right most
 * 
 * @return new placement
*/
int RandomizedPartition(int *seq, int p, int r)
{
  auto i = (rand() % (r + 1 - p)) + p;

  // swap value
  swap(seq[r], seq[i]);

  /**
   * HeapSort
   * 
   * @param seq array of elements to be sorted
   * @param size length of array
  */
  auto Partition = [](int *seq, int p, int r) {
    auto x = seq[r];
    auto i = p - 1;

    for (auto j = p; j <= r - 1; j++)
    {
      if (seq[j] <= x)
      {
        i++;

        // swap value
        swap(seq[i], seq[j]);
      }
    }

    // swap value
    swap(seq[i + 1], seq[r]);

    return i + 1;
  };

  return Partition(seq, p, r);
}

/**
 * QuickSort
 * 
 * @param seq array of elements to be sorted
 * @param p left most
 * @param r right most
*/
void QuickSort(int *seq, int p, int r)
{
  if (p < r)
  {
    // get random mid
    auto q = RandomizedPartition(seq, p, r);

    // Recusive QuickSort on left half
    QuickSort(seq, p, q - 1);

    // Recursive QuickSort on right half
    QuickSort(seq, q + 1, r);
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

  // Runs QuickSort algoritm on sequence
  QuickSort(Sequence, 0, arraySize - 1);

  // Print out each element in sorted array
  for (auto c = 0; c < arraySize; c++)
    cout << Sequence[c] << ';';

  // Free allocated space
  delete[] Sequence;
}
