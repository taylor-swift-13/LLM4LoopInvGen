
/*@Inv
  (\at(x, Pre) >= \at(y, Pre) && \at(y, Pre) >= 0) ==> (((i == 0) && (z3 == \at(z3, Pre)) && (z2 == \at(z2, Pre)) && (z1 == \at(z1, Pre)) && (y == \at(y, Pre)) && (x == \at(x, Pre))) || (i >= 0 && i <= y)) &&
  (\at(x, Pre) >= \at(y, Pre) && \at(y, Pre) >= 0) ==> (z3 == \at(z3, Pre)) &&
  (\at(x, Pre) >= \at(y, Pre) && \at(y, Pre) >= 0) ==> (z2 == \at(z2, Pre)) &&
  (\at(x, Pre) >= \at(y, Pre) && \at(y, Pre) >= 0) ==> (z1 == \at(z1, Pre)) &&
  (\at(x, Pre) >= \at(y, Pre) && \at(y, Pre) >= 0) ==> (y == \at(y, Pre)) &&
  (\at(x, Pre) >= \at(y, Pre) && \at(y, Pre) >= 0) ==> (x == \at(x, Pre))
*/
while (unknown()) {
    if (i < y) {
        i = (i + 1);
    }
    
    /*@ assert (i < y) ==> (i >= 0); */
}
