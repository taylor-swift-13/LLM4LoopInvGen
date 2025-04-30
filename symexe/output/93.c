
/*@Inv
  (\at(n, Pre) >= 0) => ((0 < \at(n, Pre)) => (((y == 0) && (x == 0) && (i == 0) && (n == \at(n, Pre))) || (x + y == 3 * i))) &&
  (\at(n, Pre) >= 0) => ((!(0 < \at(n, Pre))) => ((y == 0) && (x == 0) && (i == 0) && (n == \at(n, Pre)))) &&
  (\at(n, Pre) >= 0) => (n == \at(n, Pre))
*/
while (i < n) {
    i = i + 1;
    if (1) {
        x = x + 1;
        y = y + 2;
    } else {
        x = x + 2;
        y = y + 1;
    }
}
