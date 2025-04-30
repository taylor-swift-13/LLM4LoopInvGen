
/*@Inv
  ((x == 0) && (z == z@pre) && (y == y@pre)) || (PLACE_HOLDER_y) &&
  ((x == 0) && (z == z@pre) && (y == y@pre)) || (PLACE_HOLDER_x) &&
  z == z@pre
*/
while(x < 500) {
    x += 1;
    if( z <= y) {
        y = z;
    }
}
