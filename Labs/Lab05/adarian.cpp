#include <iostream>
#include <vector>

#define length 10

using namespace std;

vector<vector<int>> CountingSort(vector<vector<int>> container, vector<int> vec) {
  vector<int> Count(length,0);
  vector<vector<int>> temp;
  temp.resize(vec.size());
  
  for (int i = 0; i < vec.size(); i++) {
    Count[vec[i]]++;
  }

  for (int i = 1; i < Count.size(); i++) {
    Count[i] += Count[i - 1];
  }

  for (int i = 0; i < vec.size(); i++) {
    temp[i].resize(length);
  }

  for (int i = vec.size()-1; i >= 0; i--) {
    swap(temp[Count[vec[i]] - 1], container[i]);
    Count[vec[i]] -= 1;
  }

  return temp;
}

void RadixSort(vector<vector<int>> container) {
  for (int i = length - 1; i >= 0; i--) {
    vector<int> vec;
    for (int j = 0; j < container.size(); j++ )
      vec.push_back(container[j][i]);
    container = CountingSort(container, vec);
  }
  
  for(int i = 0; i < container.size(); i++){
    for (int j = 0; j < container[i].size(); j++){
      cout << container[i][j] << ";";
    }
    cout << endl;
  }
}

int main(int argc, const char* argv[]) {
  vector<vector<int>> container;
  int val;
  int vecSize = 0;

  // Get the size of each sequence
  cin >> vecSize;
  container.resize(vecSize);
  
  // Read the sequences
  for(int i = 0; i < vecSize; i++) {
    for(int j = 0; j < length; j++) {
      cin >> val;
      container[i].push_back(val);
    }
  }

  RadixSort(container);

  return 0;
}


