#ifndef COMBINATORICS_H
#define COMBINATORICS_H

#include <vector>

namespace combinatorics {
  //======================= Functions =======================//
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
  unsigned long long combinations(int n, int r);

  /**
   * @brief Returns the number of permutations of r objects from a set of n
   *        objects.
   *
   * Returns the result of the typical nPr function, which is equal to:
   *  (n!)/((n-r)!)
   * for all r <= n, and
   *  0
   * for all r > n
   *
   * @param n the integer number of objects in the set to choose from
   * @param r the integer number of objects to select from a set of n objects
   * @return the number of permutations of r objects from n
   */
  unsigned long long permutations(int n, int r);

  /**
   * @brief Returns the factorial of n (the consecutive product from 1 to n).
   *        factorial is defined to be 1 for n == 0.
   *
   * @param n the integer to take the factorial of
   * @return the calculated factorial of n
   */
  unsigned long long factorial(int n);

  //======================= Classes and Structs =======================//
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
    /// All of the functions that have access to this class' static members
    friend unsigned long long combinations(int n, int r);
    friend unsigned long long permutations(int n, int r);
    friend unsigned long long factorial(int n);

   private:
    static_resources(); /// Private constructor; can't be instantiated

    // Create Pascal's triangle as a static 2D vector, for keeping
    // previously-computed values between function calls
    static std::vector<std::vector<unsigned long long> > pascal;
    static int greatestPascal_n, greatestPascal_r;

    // Keep consecutive products for use in permutations and factorial
    static std::vector<unsigned long long> consecutiveProduct;
    static bool productsFilled;

    // Returns the consecutive product from first to last, inclusive
    static unsigned long long rangeProduct(int first, int last);
  };

  //======================= Static Initialization =======================//
  // Pascal's triangle
  // Start at size 1x1;  0C0 == 1
  std::vector<std::vector<unsigned long long> >
  static_resources::pascal(0+1, std::vector<unsigned long long>(0+1, 1));

  int static_resources::greatestPascal_n = 0,
      static_resources::greatestPascal_r = 0;

  // We can multiply consecutive integers from 1 to 20 before they don't fit
  // in unsigned long long's anymore
  std::vector<unsigned long long>
  static_resources::consecutiveProduct(21, 1);
  bool static_resources::productsFilled = false;
}

#include "combinatorics.tpp" // Template implementation file
#endif // #ifndef COMBINATORICS_H
