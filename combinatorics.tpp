#include "combinatorics.h"
#include <vector>

int combinations(int n, int r) {
  std::vector<std::vector<int> > pascal(n+1, std::vector<int>(r+1, 0));

  pascal[0][0] = 1;

  for(int i = 1; i <= n; ++i) {
    pascal[i][0] = 1;
    for(int j = 1; j <= i && j <= r; ++j)
      pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
  }

  return pascal[n][r];
}
