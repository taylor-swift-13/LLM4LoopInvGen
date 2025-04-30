
/*@Inv
  (0 <= y@pre && y@pre <= 127) ==> (((z == 36 * y@pre) && (c == 0) && (y == y@pre)) || (c < 36)) &&
  (0 <= y@pre && y@pre <= 127) ==> (((z == 36 * y@pre) && (c == 0) && (y == y@pre)) || (z < 4608)) &&
  (0 <= y@pre && y@pre <= 127) ==> (y == y@pre)
*/
while (unknown()) {
    if (c < 36) {
        z = z + 1;
        c = c + 1;
    }
    /*@ assert (z < 0 && z >= 4608) ==> (c >= 36); */
}
