
/*@Inv
  (\at(x, Pre) != \at(x, Pre) + 1) ==> (((y == \at(x, Pre) + 1) && (lock == 1) && (x == \at(x, Pre))) || (x == y)) &&
  (\at(x, Pre) != \at(x, Pre) + 1) ==> (((y == \at(x, Pre) + 1) && (lock == 1) && (x == \at(x, Pre))) || (lock == 1)) &&
  (\at(x, Pre) != \at(x, Pre) + 1) ==> (((y == \at(x, Pre) + 1) && (lock == 1) && (x == \at(x, Pre))) || (y == \at(x, Pre) + 1)) &&
  !(\at(x, Pre) != \at(x, Pre) + 1) ==> ((y == \at(x, Pre) + 1) && (lock == 1) && (x == \at(x, Pre)))
*/
while (x != y) {
    if (1) {
        lock = 1;
        x = y;
    } else {
        lock = 0;
        x = y;
        y = y + 1;
    }
}
