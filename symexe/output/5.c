
/*@Inv
  (0 < size@pre) ==> (((x == 0) && (z == z@pre) && (y == y@pre) && (size == size@pre)) || (y <= z)) &&
  (0 < size@pre) ==> (((x == 0) && (z == z@pre) && (y == y@pre) && (size == size@pre)) || (x < size)) &&
  !(0 < size@pre) ==> ((x == 0) && (z == z@pre) && (y == y@pre) && (size == size@pre)) &&
  z == z@pre &&
  size == size@pre
*/
while(x < size) {
    x += 1;
    if(z <= y) {
        y = z;
    }
}
