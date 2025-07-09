#include <bits/stdc++.h>

class Solution
{
public:
  int longestValidParentheses(std::string s)
  {
    int best = 0, left = 0, right = 0;
    for (char c : s)
    {
      (c == '(' ? ++left : ++right);
      if (left == right)
        best = std::max(best, 2 * right);
      else if (right > left)
        left = right = 0;
    }
    left = right = 0;
    for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i)
    {
      (s[i] == '(' ? ++left : ++right);
      if (left == right)
        best = std::max(best, 2 * left);
      else if (left > right)
        left = right = 0;
    }
    return best;
  }
};
