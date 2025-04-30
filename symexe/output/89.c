
/*@Inv
  (\at(y, Pre) != \at(y, Pre)) ==> (((x == y@pre) && (lock == 1) && (v3 == v3@pre) && (v2 == v2@pre) && (v1 == v1@pre) && (y == y@pre)) || (PLACE_HOLDER_y)) &&
  (\at(y, Pre) != \at(y, Pre)) ==> (((x == y@pre) && (lock == 1) && (v3 == v3@pre) && (v2 == v2@pre) && (v1 == v1@pre) && (y == y@pre)) || (PLACE_HOLDER_lock)) &&
  (\at(y, Pre) != \at(y, Pre)) ==> (((x == y@pre) && (lock == 1) && (v3 == v3@pre) && (v2 == v2@pre) && (v1 == v1@pre) && (y == y@pre)) || (PLACE_HOLDER_x)) &&
  !(\at(y, Pre) != \at(y, Pre)) ==> ((x == y@pre) && (lock == 1) && (v3 == v3@pre) && (v2 == v2@pre) && (v1 == v1@pre) && (y == y@pre)) &&
  v3 == v3@pre &&
  v2 == v2@pre &&
  v1 == v1@pre
*/
while (x != y) {
    if (1) {
        lock  = 1;
        x  = y;
    } else {
        lock  = 0;
        x  = y;
        y  = y + 1;
    }
}
