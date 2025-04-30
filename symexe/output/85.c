
/*@Inv
  (x == -15000 + (y - y@pre) * (y + 1)) &&
  (z3 == z3@pre) &&
  (z2 == z2@pre) &&
  (z1 == z1@pre) &&
  (y == y@pre + (1 - (x + 15000) / y@pre))
*/
while (x < 0) {
    x  = x + y;
    y  = y + 1;
}

/*@ assert y > 0; */
