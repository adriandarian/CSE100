#include <iostream>

#define MAX_INT 2147483647

using namespace std;
  
/*
 * description: Recursive MergeSort
 * 
 * @params  seq   array of numbers
 * @params  l     beginning of array
 * @params  r     end of array
 */
void mergeSort(int* seq, int l, int r) { 
  if (l < r) { 
    // Create middle placeholder
    int m = (l + r) / 2; 

    mergeSort(seq, l, m); 
    mergeSort(seq, m + 1, r); 

    // Merge two numbers backwards as a lambda function
    auto merge = [&]() {
      auto i = 0, j = 0, k = l, n1 = m - l + 1, n2 =  r - m;
      int L[n1], R[n2]; 

      for (i; i < n1; i++) 
        L[i] = seq[l + i]; 
      
      for (j; j < n2; j++) 
        R[j] = seq[m + 1 + j]; 
      
      i = 0, j = 0;

      while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
          seq[k] = L[i]; 
          i++; 
        } else { 
          seq[k] = R[j]; 
          j++; 
        } 
        k++; 
      } 

      while (i < n1) { 
        seq[k] = L[i]; 
        i++; 
        k++; 
      } 

      while (j < n2) { 
        seq[k] = R[j]; 
        j++; 
        k++; 
      } 
    };

    // Call lambda function
    merge(); 
  } 
} 

int main(int argc, char **argv) {

  int* Sequence;
  auto arraySize = 1;

  // Get the size of the sequence
  cin >> arraySize;
  Sequence = new int[arraySize];
    
  // Read the sequence
  for(auto i = 0; i < arraySize; i++)
    cin >> Sequence[i];

  mergeSort(Sequence, 0, arraySize - 1);

  for (auto i = 0; i < arraySize; i++) {
    cout << Sequence[i] << ';';
  }

  // Free allocated space
  delete[] Sequence;
}
