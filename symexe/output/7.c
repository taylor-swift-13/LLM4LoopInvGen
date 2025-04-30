
/*@Inv
  (\at(x, Pre) >= 0 && \at(x, Pre) <= 10 && \at(y, Pre) <= 10 && \at(y, Pre) >= 0) => (((y == \at(y, Pre)) && (x == \at(x, Pre))) || (x >= 0 && x <= 20)) &&
  (\at(x, Pre) >= 0 && \at(x, Pre) <= 10 && \at(y, Pre) <= 10 && \at(y, Pre) >= 0) => (((y == \at(y, Pre)) && (x == \at(x, Pre))) || (y >= 0 && y <= 20))
*/
while (1) {
    x = x + 10;
    y = y + 10;
    
    /*@ assert (x == 20) ==> (y != 0); */
}
