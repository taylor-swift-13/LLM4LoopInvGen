
/*@Inv
  (0 <= y@pre && y@pre <= 127) ==> (((z == 36 * y@pre) && (c == 0) && (y == y@pre)) || (c < 36)) &&
  (0 <= y@pre && y@pre <= 127) ==> (((z == 36 * y@pre) && (c == 0) && (y == y@pre)) || (z >= 36 * y@pre)) &&
  (0 <= y@pre && y@pre <= 127) ==> (y == y@pre)
*/
while (unknown()) {
    if (c < 36) {
        z = z + 1;
        c = c + 1;
    }
    /*@ assert (c < 36) ==> (z >= 0); */
}
