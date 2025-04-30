
/*@Inv
  (\at(x, Pre) != 0) ==> (((j == y@pre) && (i == x@pre) && (z3 == z3@pre) && (z2 == z2@pre) && (z1 == z1@pre) && (y == y@pre) && (x == x@pre)) || (PLACE_HOLDER_x)) &&
  (\at(x, Pre) != 0) ==> (((j == y@pre) && (i == x@pre) && (z3 == z3@pre) && (z2 == z2@pre) && (z1 == z1@pre) && (y == y@pre) && (x == x@pre)) || (PLACE_HOLDER_y)) &&
  !(\at(x, Pre) != 0) ==> ((j == y@pre) && (i == x@pre) && (z3 == z3@pre) && (z2 == z2@pre) && (z1 == z1@pre) && (y == y@pre) && (x == x@pre)) &&
  j == y@pre &&
  i == x@pre &&
  z3 == z3@pre &&
  z2 == z2@pre &&
  z1 == z1@pre
*/
while (x != 0) {
    x = x - 1;
    y = y - 1;
}
