
/*@Inv
  (x@pre >= 0 && x@pre <= 2 && y@pre <= 2 && y@pre >= 0) => 
  (((z3 == z3@pre) && (z2 == z2@pre) && (z1 == z1@pre) && (y == y@pre) && (x == x@pre)) || (PLACE_HOLDER_x)) &&
  (x@pre >= 0 && x@pre <= 2 && y@pre <= 2 && y@pre >= 0) => 
  (((z3 == z3@pre) && (z2 == z2@pre) && (z1 == z1@pre) && (y == y@pre) && (x == x@pre)) || (PLACE_HOLDER_y)) &&
  (x@pre >= 0 && x@pre <= 2 && y@pre <= 2 && y@pre >= 0) => (z3 == z3@pre) &&
  (x@pre >= 0 && x@pre <= 2 && y@pre <= 2 && y@pre >= 0) => (z2 == z2@pre) &&
  (x@pre >= 0 && x@pre <= 2 && y@pre <= 2 && y@pre >= 0) => (z1 == z1@pre)
*/
while (1) {
    x  = x + 2;
    y  = y + 2;

    /*@ assert (x == 4) ==> (y != 0);  */
}
