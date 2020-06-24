#include <iostream>

#define MAX_INT 2147483647

using namespace std;

int main(int argc, char **argv)
{

  int *Sequence;
  auto arraySize = 1;

  // Get the size of the sequence
  cin >> arraySize;
  Sequence = new int[arraySize];

  // Read the sequence
  for (auto i = 0; i < arraySize; i++)
  {
    cin >> Sequence[i];
  }

  /*
   * Insertion Sort as a lambda function
   * 
   * @params & sign allows function to take in all variables in the current parent scope
   */ 
  auto result = [&]() {
    // Iterate through Sequence array starting from the 2nd index
    for (auto j = 1; j < arraySize; j++)
    {
      /*
       * Assign current element in array to key
       * set the i as a placeholder for the previous element
       */
      auto key = Sequence[j], i = j - 1;

      /*
       * Check if the placeholder will be a value in the array
       * Check if element at i is greater to the current place in the array
       */
      while (i >= 0 && Sequence[i] > key)
      {
        // Shift the previous element up by 1 place
        Sequence[i + 1] = Sequence[i];

        // Decrease the placeholder by 1
        i--;
      }

      // Assign element that was not sorted to it's correct place
      Sequence[i + 1] = key;

      // Iterate from the beginning to the current place and print each value of array
      for (auto x = 0; x <= j; x++)
      {
        cout << Sequence[x] << ";";
      }

      cout << endl;
    }
  };

  // Call Lambda Function
  result();

  // Free allocated space
  delete[] Sequence;
}
