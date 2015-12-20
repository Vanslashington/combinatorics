#include "combinatorics.h"
#include <vector>
#include <algorithm>

/**
 * Rather than computing factorials, we build Pascal's triangle and take nCr
 * from row n and column r of the triangle.  For all r > n, nCr is defined
 * as 0.
 *
 * The triangle is built in a bottom-up DP fashion, computing each cell by
 * adding the two corresponding cells from the previous row.
 *
 * @TODO Template the function so that it effectively takes long, long long,
 *       etc.  Improve the dynamic expansion methodology to be more efficient.
 *       Add measures to protect against overflows.
 */
int combinations(int n, int r) {
  /// nCr = 0 for all r > n
  if(r > n) return 0;

  // Aliases for brevity
  std::vector<std::vector<int> >& pascal = static_resources::pascal;
  int& greatestPascal_n = static_resources::greatestPascal_n;
  int& greatestPascal_r = static_resources::greatestPascal_r;

  /// Expand the triangle "rectangularly" downward until we've computed nCr
  if(r > greatestPascal_r) {
    for(int i = 1; i <= greatestPascal_n; ++i) {
      pascal[i].resize(std::min(i+1, r+1), 1);
      for(int j = greatestPascal_r+1; j < i && j <= r; ++j)
        pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
    }
    greatestPascal_r = r;
  }
  if(n > greatestPascal_n) {
    pascal.resize(n+1, std::vector<int>());
    for(int i = greatestPascal_n+1; i <= n; ++i) {
      pascal[i].resize(std::min(i+1, greatestPascal_r+1), 1);
      for(int j = 1; j < i && j <= greatestPascal_r; ++j)
        pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
    }
    greatestPascal_n = n;
  }

  /// The value at row n and column r of the triangle is now computed
  return pascal[n][r];
}
