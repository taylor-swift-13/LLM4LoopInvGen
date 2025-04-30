
/*@Inv
  (0 < n@pre) ==> (((m <= x) && (x == 0) && (z3 == z3@pre) && (z2 == z2@pre) && (z1 == z1@pre) && (n == n@pre)) || (m < n)) &&
  !(0 < n@pre) ==> ((m == 0) && (x == 0) && (z3 == z3@pre) && (z2 == z2@pre) && (z1 == z1@pre) && (n == n@pre)) &&
  z3 == z3@pre &&
  z2 == z2@pre &&
  z1 == z1@pre &&
  n == n@pre
*/
while (x < n) {

    if (1) {
        m = x;
    }
    
    x = x + 1;
}
