
/*@Inv
  (\at(a, Pre) <= \at(m, Pre)) ==> ((0 < \at(c, Pre)) ==> (((k == 0) && (c == \at(c, Pre)) && (a == \at(a, Pre)) && (j == \at(j, Pre)) && (m == \at(m, Pre))) || (m >= a))) &&
  (\at(a, Pre) <= \at(m, Pre)) ==> ((0 < \at(c, Pre)) ==> (((k == 0) && (c == \at(c, Pre)) && (a == \at(a, Pre)) && (j == \at(j, Pre)) && (m == \at(m, Pre))) || (k < c))) &&
  (\at(a, Pre) <= \at(m, Pre)) ==> ((!(0 < \at(c, Pre))) ==> ((k == 0) && (c == \at(c, Pre)) && (a == \at(a, Pre)) && (j == \at(j, Pre)) && (m == \at(m, Pre)))) &&
  (\at(a, Pre) <= \at(m, Pre)) ==> (c == \at(c, Pre)) &&
  (\at(a, Pre) <= \at(m, Pre)) ==> (a == \at(a, Pre)) &&
  (\at(a, Pre) <= \at(m, Pre)) ==> (j == \at(j, Pre))
*/
while (k < c) {
    if (m < a) {
        m = a;
    }
    k = k + 1;
}
