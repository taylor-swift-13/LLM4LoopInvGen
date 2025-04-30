
/*@Inv
  (\at(x, Pre) >= 0 && \at(x, Pre) <= 2 && \at(y, Pre) <= 2 && \at(y, Pre) >= 0) => (x >= x@pre + 2 * n && y >= y@pre + 2 * n) &&
  (\at(x, Pre) >= 0 && \at(x, Pre) <= 2 && \at(y, Pre) <= 2 && \at(y, Pre) >= 0) => (z3 == z3@pre) &&
  (\at(x, Pre) >= 0 && \at(x, Pre) <= 2 && \at(y, Pre) <= 2 && \at(y, Pre) >= 0) => (z2 == z2@pre) &&
  (\at(x, Pre) >= 0 && \at(x, Pre) <= 2 && \at(y, Pre) <= 2 && \at(y, Pre) >= 0) => (z1 == z1@pre)
*/
