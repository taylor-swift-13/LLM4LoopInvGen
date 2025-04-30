
/*@Inv
  (0 < n@pre) ==> ((m == 0) && (x == 0) && (n@pre) || (x < n)) &&
  (0 < n@pre) ==> ((m == 0) && (x == 0) && (n@pre) || (m == x)) &&
  !(0 < n@pre) ==> ((m == 0) && (x == 0) && (n@pre)) &&
  n == n@pre
*/
while (x < n) {
    if (1) {
        m = x;
    }
    x = x + 1;
}
