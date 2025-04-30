
/*@Inv
  (0 <= x@pre) ==> (((y == 2) && (j == 0) && (i == 0) && (x == x@pre)) || (PLACE_HOLDER_i)) &&
  (0 <= x@pre) ==> (((y == 2) && (j == 0) && (i == 0) && (x == x@pre)) || (PLACE_HOLDER_j)) &&
  !(0 <= x@pre) ==> ((y == 2) && (j == 0) && (i == 0) && (x == x@pre)) &&
  y == 2 &&
  x == x@pre
*/
while (i <= x) {
    i = i + 1;
    j = j + y;
}
