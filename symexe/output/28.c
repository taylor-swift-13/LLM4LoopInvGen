
/*@Inv
  (\at(n, Pre) > 0) ==> (((x == \at(n, Pre)) && (n == \at(n, Pre))) || (x == \at(n, Pre) - k && 0 <= k && k <= \at(n, Pre))) &&
  !(\at(n, Pre) > 0) ==> ((x == \at(n, Pre)) && (n == \at(n, Pre))) &&
  n == \at(n, Pre)
*/
