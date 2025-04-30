
/*@Inv
  (\at(x, Pre) >= 0 && \at(x, Pre) <= 10 && \at(y, Pre) <= 10 && \at(y, Pre) >= 0) => (x >= 0 && y >= 0) &&
  (\at(x, Pre) >= 0 && \at(x, Pre) <= 10 && \at(y, Pre) <= 10 && \at(y, Pre) >= 0) => (z3 == z3@pre) &&
  (\at(x, Pre) >= 0 && \at(x, Pre) <= 10 && \at(y, Pre) <= 10 && \at(y, Pre) >= 0) => (z2 == z2@pre) &&
  (\at(x, Pre) >= 0 && \at(x, Pre) <= 10 && \at(y, Pre) <= 10 && \at(y, Pre) >= 0) => (z1 == z1@pre)
*/
while (1) {
    x = x + 10;
    y = y + 10;

    /*@ assert (x == 20) ==>  (y != 0); */
}
