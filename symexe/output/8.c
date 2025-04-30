
/*@Inv
  (\at(x, Pre) >= 0 && \at(x, Pre) <= 10 && \at(y, Pre) <= 10 && \at(y, Pre) >= 0) => (x >= \at(x, Pre) + 10 * n && y >= \at(y, Pre) + 10 * n) &&
  (\at(x, Pre) >= 0 && \at(x, Pre) <= 10 && \at(y, Pre) <= 10 && \at(y, Pre) >= 0) => (x >= \at(x, Pre) + 10 * n && y >= \at(y, Pre) + 10 * n)
*/
while (1) {
    x = x + 10;
    y = y + 10;
    
    /*@ assert (y == 0) ==>  (x != 20); */
}
