
/*@Inv
  (\at(x, Pre) >= \at(y, Pre) && \at(y, Pre) >= 0) ==> (((i == 0)&&(y == \at(y, Pre))&&(x == \at(x, Pre))) || (i < \at(y, Pre))) &&
  (\at(x, Pre) >= \at(y, Pre) && \at(y, Pre) >= 0) ==> (y == \at(y, Pre)) &&
  (\at(x, Pre) >= \at(y, Pre) && \at(y, Pre) >= 0) ==> (x == \at(x, Pre))
*/
