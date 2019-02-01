#include <iostream>

#define MAX_INT 2147483647

using namespace std;

// void mergeSort(int* seq, int l, int r) {
//   if (l < r) {
//     int m = (l + r) / 2;
//     mergeSort(seq, l, m);
//     mergeSort(seq, m + 1, r);
//     auto merge =  [&]() {
//       int a = m - l + 1;
//       int b = r - m;
//       int L[a];
//       int R[b];
//       for (int i = 0; i < a; i++) {
//         L[i] = seq[l + i - 1];
//       }
//       for (int j = 0; j < b; j++) {
//         R[j] = seq[m + j];
//       }
//       L[a + 1] = MAX_INT;
//       R[b + 1] = MAX_INT;
//       int i = 1;
//       int j = 1;
//       for (int k = l; k < r; k++) {
//         if (L[i] <= R[j]) {
//           seq[k] = L[i];
//           i++;
//         } else if (seq[k] == R[j]) {
//           j++;
//         }
//       }

//       for (int c = 0; c < r; c++) {
//         cout << seq[c] << ';';
//       }
//     };
//     merge();
//   }
// }


  
void mergeSort(int* seq, int l, int r) { 
  if (l < r) { 
    int m = (l + r) / 2; 
    mergeSort(seq, l, m); 
    mergeSort(seq, m + 1, r); 
    auto merge = [&]() {
      int i, j, k; 
      int n1 = m - l + 1; 
      int n2 =  r - m; 
      int L[n1], R[n2]; 
      for (i = 0; i < n1; i++) 
        L[i] = seq[l + i]; 
      for (j = 0; j < n2; j++) 
        R[j] = seq[m + 1 + j]; 
      i = 0;
      j = 0; 
      k = l;
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
    merge(); 
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

  mergeSort(Sequence, 0, arraySize-1);

  for (int c = 0; c < arraySize; c++) {
    cout << Sequence[c] << ';';
  }

  // Free allocated space
  delete[] Sequence;
}
