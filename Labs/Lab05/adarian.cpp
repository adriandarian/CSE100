#include <iostream>
#include <vector>

#define length 10

using namespace std;

/**
 * RadixSort
 * 
 * @param container 2D list of numbers
*/
void RadixSort(vector<vector<int>> container)
{
  /**
   * CountingSort
   * 
   * @param container 2D list of numbers
   * @param vec sub list from the main container
   * 
   * @return 2D list of numbers
  */
  auto CountingSort = [&](vector<vector<int>> container, vector<int> vec) {
    vector<int> Count(length, 0);
    vector<vector<int>> temp;
    temp.resize(vec.size());

    for (auto i = 0; i < vec.size(); i++)
    {
      Count[vec[i]]++;
    }

    for (auto i = 1; i < Count.size(); i++)
    {
      Count[i] += Count[i - 1];
    }

    for (auto i = 0; i < vec.size(); i++)
    {
      temp[i].resize(length);
    }

    for (int i = vec.size() - 1; i >= 0; i--)
    {
      swap(temp[Count[vec[i]] - 1], container[i]);
      Count[vec[i]] -= 1;
    }

    return temp;
  };

  // Algorithm for RadixSort
  for (auto i = length - 1; i >= 0; i--)
  {
    vector<int> vec;

    for (auto j = 0; j < container.size(); j++)
    {
      vec.push_back(container[j][i]);
    }

    container = CountingSort(container, vec);
  }

  /**
   * Print
   * 
   * @param container 2D list of numbers
   * 
   * @return nothing because it will call a print lambda function to print to the console the sorted list
  */
  auto print = [&]() {
    for (auto i = 0; i < container.size(); i++)
    {
      for (auto j = 0; j < container[i].size(); j++)
      {
        cout << container[i][j] << ";";
      }

      cout << endl;
    }
  };

  print();
}

int main(int argc, const char *argv[])
{
  vector<vector<int>> container;
  int val;
  auto vecSize = 0;

  // Get the size of each sequence
  cin >> vecSize;
  container.resize(vecSize);

  // Read the sequences
  for (auto i = 0; i < vecSize; i++)
  {
    for (auto j = 0; j < length; j++)
    {
      cin >> val;
      container[i].push_back(val);
    }
  }

  // Performs RadixSort on 2D list of numbers
  RadixSort(container);

  return 0;
}
