#include <iostream>
#include <climits>

using namespace std;

class ReverseInteger
{
public:
  int reverseInt(int n)
  {

    int ans = 0;
    while (n != 0)
    {

      int digit = n % 10;

      // INT_MAX =  2147483647 || INT_MIN = -2147483648
      // Positive Overflow
      if (ans > INT_MAX / 10 ||
          (ans == INT_MAX / 10 && digit > 7))
        return 0;

      // Negative Overflow
      if (ans < INT_MIN / 10 ||
          (ans == INT_MIN / 10 && digit < -8))
        return 0;

      // Build the reversed number
      ans = ans * 10 + digit;
      n /= 10;
    }
    return ans;
  }
};

int main()
{

  int n;
  cin >> n;

  ReverseInteger rev;
  cout << rev.reverseInt(n);

  return 0;
}

/*
=====================================================
Time Complexity
-----------------------------------------------------
O(log10 N)

Reason:
Each iteration removes one digit using:

   -> n /= 10;

An integer with d digits executes the loop exactly d times.

Examples:
12345   -> 5 iterations
120     -> 3 iterations
7       -> 1 iteration

=====================================================
Space Complexity
-----------------------------------------------------
O(1)

Reason:
Only a few integer variables are used:

    ->ans
    ->digit
    ->n

No arrays, vectors, strings, recursion, or extra memory
are allocated.

*/