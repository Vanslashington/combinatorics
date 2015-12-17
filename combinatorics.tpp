#include "combinatorics.h"
#include <vector>

/**
 * Rather than computing factorials, we build Pascal's triangle and take nCr
 * from the row n and column r of the triangle.  For all r > n, nCr is defined
 * as 0.
 *
 * The triangle is built in a bottom-up DP fashion, computing each cell by
 * adding the two corresponding cells from the previous row.
 *
 * @TODO Template the function so that it effectively takes long, long long,
 *       etc.  Cache the computed triangle in some way so that it is not
 *       recomputed every time the function is called.
 */
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
