#include "combinatorics.h"
#include <algorithm>

//======================= Public Functions =======================//
/**
 * Rather than computing factorials, we build Pascal's triangle and take nCr
 * from row n and column r of the triangle.  For all r > n, nCr is defined
 * as 0.
 *
 * The triangle is built in a bottom-up DP fashion, computing each cell by
 * adding the two corresponding cells from the previous row.
 *
 * @TODO Template the function so that it effectively takes long, long long,
 *       etc.  Add measures to protect against overflows and negatives.
 *       Unsigned long long's can only handle up to about 67C33;  just
 *       precompute all of them beforehand.
 */
unsigned long long combinatorics::combinations(int n, int r) {
  /// nCr = 0 for all r > n
  if(r > n) return 0;

  // typedef and aliases for brevity
  typedef unsigned long long ull;
  std::vector<std::vector<ull> >& pascal = static_resources::pascal;
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
    pascal.resize(n+1, std::vector<ull>());
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

/**
 * For r > n, return 0.
 * Otherwise, return the consecutive product from (n-r)+1 to n.
 *
 * @TODO Check for negatives and overflows
 */
unsigned long long combinatorics::permutations(int n, int r) {
  if(r > n) return 0;
  return static_resources::rangeProduct((n-r)+1, n);
}

/**
 * For n == 0, return 1.
 * Otherwise, return the consecutive product from 1 to n.
 *
 * @TODO check for negatives and overflows
 */
unsigned long long combinatorics::factorial(int n) {
  if(n == 0) return 1;
  return static_resources::rangeProduct(1, n);
}

//======================= Private Functions =======================//
/**
 * Return the consecutive product from first to last.
 *
 * @TODO Just precompute a large number of them (every one that can fit in
 *       unsigned long long?) beforehand.
 */
unsigned long long
combinatorics::static_resources::rangeProduct(int first, int last) {
  if(first > last) return 1;
  if(first == 0) return 0;

  if(productsFilled == false) {
    for(int i = 2; i <= 20; ++i)
      consecutiveProduct[i] = consecutiveProduct[i-1] * i;
    productsFilled = true;
  }

  if(first == 1) return consecutiveProduct[last];
  return consecutiveProduct[last] / consecutiveProduct[first-1];
}
