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

  // typedef's for brevity and readability
  typedef int              T;
  typedef std::vector<T>   vec;
  typedef std::vector<vec> vec2d;

  /// Create Pascal's triangle as a static 2D vector, because we want
  /// previously-computed results to be saved for future calls of the function
  static vec2d pascal(0+1, vec(0+1, 1)); // Start at size 1x1;  0C0 == 1
  static int greatestComputed_n = 0, greatestComputed_r = 0;

  /// Expand the triangle "rectangularly" downward until we've computed nCr
  if(r > greatestComputed_r) {
    for(int i = 1; i <= greatestComputed_n; ++i) {
      pascal[i].resize(std::min(i+1, r+1), 1);
      for(int j = greatestComputed_r+1; j < i && j <= r; ++j)
        pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
    }
    greatestComputed_r = r;
  }
  if(n > greatestComputed_n) {
    pascal.resize(n+1, vec());
    for(int i = greatestComputed_n+1; i <= n; ++i) {
      pascal[i].resize(std::min(i+1, greatestComputed_r+1), 1);
      for(int j = 1; j < i && j <= greatestComputed_r; ++j)
        pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
    }
    greatestComputed_n = n;
  }

  /// The value at row n and column r of the triangle is now computed
  return pascal[n][r];
}
