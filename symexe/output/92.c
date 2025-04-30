
/*@Inv
  (y == 0) && (x == 0) && (z3 == z3@pre) && (z2 == z2@pre) && (z1 == z1@pre) &&
  (y >= 0)
*/
while(y >= 0) {
    y = y + x;
}

/*@ assert y >= 0;*/
