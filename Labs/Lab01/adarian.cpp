#include <iostream>

#define MAX_INT 2147483647

using namespace std;

int main(int argc, char **argv) {

  int* Sequence;
  int arraySize = 1;

  // Get the size of the sequence
  cin >> arraySize;
  Sequence = new int[arraySize];
    
  // Read the sequence
  for(int i=0; i<arraySize; i++)
    cin >> Sequence[i];

  // insertion sort as a lambda function
  auto result = [&]() {
    int counter = 2;
    for (int j = 1; j < arraySize; j++) {
      int key = Sequence[j], i = j - 1;
      while (i >= 0 && Sequence[i] > key) {
        Sequence[i + 1] = Sequence[i];
        i--;
      }  
      Sequence[i + 1] = key;
      for (int x = 0; x < counter; x++) {
        cout << Sequence[x] << ";";
      }
      counter++;
      cout << endl;
    }
  };

  result();

  // Free allocated space
  delete[] Sequence;
}