/*
 * Main
 */
#include <iostream>
#include "matrix.hpp"

int main()
{
   Matrix<int> m1(2, 2);
   std::cin >> m1;
   Matrix<int> m2 = m1;
   int max = m2.findMax();
   m2[0][0] = max;
   std::cout << m2;
}
