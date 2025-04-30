
/*@Inv
  (\at(n, Pre) >= 0 && \at(k, Pre) >= 0) ==> ((0 <= \at(n, Pre)) ==> (((j == 0) && (i == 0) && (k == \at(k, Pre)) && (n == \at(n, Pre))) || (i <= n))) &&
  (\at(n, Pre) >= 0 && \at(k, Pre) >= 0) ==> ((0 <= \at(n, Pre)) ==> (((j == 0) && (i == 0) && (k == \at(k, Pre)) && (n == \at(n, Pre))) || (j == (i * (i + 1)) / 2))) &&
  (\at(n, Pre) >= 0 && \at(k, Pre) >= 0) ==> (!(0 <= \at(n, Pre)) ==> ((j == 0) && (i == 0) && (k == \at(k, Pre)) && (n == \at(n, Pre)))) &&
  (\at(n, Pre) >= 0 && \at(k, Pre) >= 0) ==> (k == \at(k, Pre)) &&
  (\at(n, Pre) >= 0 && \at(k, Pre) >= 0) ==> (n == \at(n, Pre))
*/
while (i <= n) {
    i = i + 1;
    j = j + i;
}
