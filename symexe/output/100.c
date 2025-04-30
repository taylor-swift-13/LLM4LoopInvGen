
/*@Inv
  (\at(n, Pre) >= 0) ==> ((\at(n, Pre) > 0) ==> (((y == 0)&&(x == \at(n, Pre))&&(n == \at(n, Pre))) || (x >= 0))) &&
  (\at(n, Pre) >= 0) ==> ((\at(n, Pre) > 0) ==> (((y == 0)&&(x == \at(n, Pre))&&(n == \at(n, Pre))) || (y == n - x))) &&
  (\at(n, Pre) >= 0) ==> ((!(\at(n, Pre) > 0)) ==> ((y == 0)&&(x == \at(n, Pre))&&(n == \at(n, Pre)))) &&
  (\at(n, Pre) >= 0) ==> (n == \at(n, Pre))
*/
while (x > 0) {
    y  = y + 1;
    x  = x - 1;
}
