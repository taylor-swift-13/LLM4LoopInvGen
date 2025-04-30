
/*@Inv
  (\at(x, Pre) >= 0 && \at(x, Pre) <= 10 && \at(y, Pre) <= 10 && \at(y, Pre) >= 0) => (((z3 == \at(z3, Pre)) && (z2 == \at(z2, Pre)) && (z1 == \at(z1, Pre)) && (y == \at(y, Pre)) && (x == \at(x, Pre))) || (PLACE_HOLDER_x)) &&
  (\at(x, Pre) >= 0 && \at(x, Pre) <= 10 && \at(y, Pre) <= 10 && \at(y, Pre) >= 0) => (((z3 == \at(z3, Pre)) && (z2 == \at(z2, Pre)) && (z1 == \at(z1, Pre)) && (y == \at(y, Pre)) && (x == \at(x, Pre))) || (PLACE_HOLDER_y)) &&
  (\at(x, Pre) >= 0 && \at(x, Pre) <= 10 && \at(y, Pre) <= 10 && \at(y, Pre) >= 0) => (z3 == \at(z3, Pre)) &&
  (\at(x, Pre) >= 0 && \at(x, Pre) <= 10 && \at(y, Pre) <= 10 && \at(y, Pre) >= 0) => (z2 == \at(z2, Pre)) &&
  (\at(x, Pre) >= 0 && \at(x, Pre) <= 10 && \at(y, Pre) <= 10 && \at(y, Pre) >= 0) => (z1 == \at(z1, Pre))
*/
while (1) {
    x = x + 10;
    y = y + 10;
    /*@ assert (y == 0) ==>  (x != 20); */
}
