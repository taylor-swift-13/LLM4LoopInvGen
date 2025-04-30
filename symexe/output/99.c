
/*@Inv
  (\at(n, Pre) > 0) ==> (((y == 0) && (x == n@pre) && (n == n@pre)) || (x >= 0)) &&
  (\at(n, Pre) > 0) ==> (((y == 0) && (x == n@pre) && (n == n@pre)) || (y == \at(n, Pre) - x)) &&
  !(\at(n, Pre) > 0) ==> ((y == 0) && (x == n@pre) && (n == n@pre)) &&
  n == n@pre
*/
while (x > 0) {
    y = y + 1;
    x = x - 1;
}
