
/*@Inv
  (1 < n@pre) ==> (((m == 1) && (x == 1) && (z3@pre) && (z2@pre) && (z1@pre) && (n@pre)) || (m <= x)) &&
  (1 < n@pre) ==> (((m == 1) && (x == 1) && (z3@pre) && (z2@pre) && (z1@pre) && (n@pre)) || (m < n)) &&
  !(1 < n@pre) ==> ((m == 1) && (x == 1) && (z3@pre) && (z2@pre) && (z1@pre) && (n@pre)) &&
  z3 == z3@pre &&
  z2 == z2@pre &&
  z1 == z1@pre &&
  n == n@pre
*/
