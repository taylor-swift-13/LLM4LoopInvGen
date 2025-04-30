
/*@Inv
  (\at(n, Pre) > 1) ==> (((x == n@pre) && (n == n@pre)) || (x > 0));
  !(\at(n, Pre) > 1) ==> ((x == n@pre) && (n == n@pre));
  n == n@pre
*/
while (x > 1) {
    x = x - 1;
}
