#ifndef COMBINATORICS_H
#define COMBINATORICS_H

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
int combinations(int n, int r);

#include "combinatorics.tpp" // Template implementation file
#endif // #ifndef COMBINATORICS_H
