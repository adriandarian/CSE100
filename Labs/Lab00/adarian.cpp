#include <iostream>

#define MAX_INT 2147483647

using namespace std;

int main(int argc, char **argv)
{
  // Initialize scoped variables
  auto amount = 1, max = 1, min = 0, tmp = 0, i = 0;

  // Get the size of the sequence
  cin >> amount;

  // Read the sequence
  do
  {
    // Updating the max and min numbers
    cin >> tmp;

    // Run once to assign min and max to the first value inserted
    if (i == 0)
    {
      max = tmp;
      min = tmp;
    }
    else
    {
      // Ternary operators to check if min or max value should be updated
      max = tmp > max ? tmp : max;
      min = tmp < min ? tmp : min;
    }

    i++;
  } while (i < amount);

  // output
  cout << max << ";" << min;
}
