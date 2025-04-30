
/*@Inv
  (0 < n@pre) ==> ((m == 0 && x == 0 && z3 == z3@pre && z2 == z2@pre && z1 == z1@pre && n == n@pre) || (x >= 0 && x <= n@pre && m == x - 1)) &&
  (0 < n@pre) ==> ((m == 0 && x == 0 && z3 == z3@pre && z2 == z2@pre && z1 == z1@pre && n == n@pre) || (x >= 0 && x <= n@pre && m == x - 1)) &&
  !(0 < n@pre) ==> (m == 0 && x == 0 && z3 == z3@pre && z2 == z2@pre && z1 == z1@pre && n == n@pre) &&
  z3 == z3@pre &&
  z2 == z2@pre &&
  z1 == z1@pre &&
  n == n@pre
*/
