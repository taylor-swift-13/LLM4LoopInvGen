
/*@Inv
  (1 <= n@pre) ==> (((sn == 0) && (i == 1) && (n@pre)) || (i > 0 && i <= n@pre)) &&
  (1 <= n@pre) ==> (((sn == 0) && (i == 1) && (n@pre)) || (sn == i - 1)) &&
  !(1 <= n@pre) ==> ((sn == 0) && (i == 1) && (n@pre)) &&
  n == n@pre
*/
while (i <= n) {
    i = (i + 1);
    sn = (sn + 1);
}
