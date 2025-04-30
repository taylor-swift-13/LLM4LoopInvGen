
/*@Inv
  !(1 < y@pre) ==> (x == 1 && z3 == z3@pre && z2 == z2@pre && z1 == z1@pre && y == y@pre) &&
  z3 == z3@pre &&
  z2 == z2@pre &&
  z1 == z1@pre &&
  y == y@pre
*/
while (x < y) {
    x = x + x;
}

/*@ assert x >= 1;*/
