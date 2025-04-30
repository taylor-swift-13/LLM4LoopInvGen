
/*@Inv
  (0 <= y@pre && y@pre <= 127) => (((z == 36 * y@pre) && (c == 0) && (x3 == x3@pre) && (x2 == x2@pre) && (x1 == x1@pre) && (y == y@pre)) || (PLACE_HOLDER_c)) &&
  (0 <= y@pre && y@pre <= 127) => (((z == 36 * y@pre) && (c == 0) && (x3 == x3@pre) && (x2 == x2@pre) && (x1 == x1@pre) && (y == y@pre)) || (PLACE_HOLDER_z)) &&
  (0 <= y@pre && y@pre <= 127) => (x3 == x3@pre) &&
  (0 <= y@pre && y@pre <= 127) => (x2 == x2@pre) &&
  (0 <= y@pre && y@pre <= 127) => (x1 == x1@pre) &&
  (0 <= y@pre && y@pre <= 127) => (y == y@pre)
*/
while (unknown()) {
    if (c < 36) {
        z = z + 1;
        c = c + 1;
    }
    /*@ assert (z < 0 && z >= 4608) => (c >= 36); */
}
