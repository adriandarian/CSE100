#include <iostream>

#define MAX_INT 2147483647

using namespace std;
  

void insertionSort(int *seq, int size) {
  for (int j = 1; j < size; j++) {
    int key = seq[j], i = j - 1;
    while (i >= 0 && seq[i] > key) {
      seq[i + 1] = seq[i];
      i--;
    }  
    seq[i + 1] = key;
  }
  
  for (int x = 0; x < size; x++) {
    cout << seq[x] << ";";
  }
}

int main(int argc, char **argv) {

  int* Sequence;
  int arraySize = 1;

  // Get the size of the sequence
  cin >> arraySize;
  Sequence = new int[arraySize];
    
  // Read the sequence
  for(int i=0; i<arraySize; i++)
    cin >> Sequence[i];

  insertionSort(Sequence, arraySize);

  // Free allocated space
  delete[] Sequence;

}
