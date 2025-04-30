
/*@Inv
  (x@pre >= y@pre && y@pre >= 0) ==> (((i == 0) && (y == y@pre) && (x == x@pre)) || (PLACE_HOLDER_i)) &&
  (x@pre >= y@pre && y@pre >= 0) ==> (y == y@pre) &&
  (x@pre >= y@pre && y@pre >= 0) ==> (x == x@pre)
*/
while (unknown()) {
    if (i < y) {
        i = (i + 1);
    }

    /*@ assert (i < y) ==> (i < x); */
}
