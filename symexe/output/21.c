
/*@Inv
  (1 < n) ==> (m < n) &&
  (n <= 1) ==> (m == 1 && x == 1 && z3 == z3@pre && z2 == z2@pre && z1 == z1@pre) &&
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

/*@ assert (n > 0) ==> (m < n); */
