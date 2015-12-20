#ifndef COMBINATORICS_H
#define COMBINATORICS_H

#include <vector>

/**
 * @brief Uninstantiable class to hold static objects and variables needed
 *        by combinatorial functions
 *
 * This class will not have any public functions of its own, only outside
 * friend functions that can make use of the variables and objects inside of
 * the class.
 */
class static_resources {
 public:
  /**
   * @brief Returns the number of combinations of r objects from a set of n
   *        objects.
   *
   * Returns the result of the typical nCr function, which is equal to:
   *  (n!)/((n-r)! * r!)
   * for all r <= n, and
   *  0
   * for all r > n
   *
   * @param n the integer number of objects in the set to choose from
   * @param r the integer number of objects to select from a set of n objects
   * @return the number of combinations of r objects from n
   */
  friend int combinations(int n, int r);

 private:
  static_resources(); // Private constructor; can't be instantiated

  /// Create Pascal's triangle as a static 2D vector, for keeping
  /// previously-computed values between function calls
  static std::vector<std::vector<int> > pascal;
  static int greatestPascal_n, greatestPascal_r;
};

// Pascal's triangle
// Start at size 1x1;  0C0 == 1
std::vector<std::vector<int> >
static_resources::pascal(0+1, std::vector<int>(0+1, 1));

int static_resources::greatestPascal_n = 0,
    static_resources::greatestPascal_r = 0;

// Combinatorial function prototypes
int combinations(int n, int r);

#include "combinatorics.tpp" // Template implementation file
#endif // #ifndef COMBINATORICS_H
