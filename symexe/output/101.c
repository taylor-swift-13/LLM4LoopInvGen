
/*@Inv
  (0 < n@pre) ==> (((x == 0) && (n@pre)) || (x == n@pre)) &&
  !(0 < n@pre) ==> ((x == 0) && (n@pre)) &&
  n == n@pre
*/
while (x < n) {
    x = (x + 1);
}
