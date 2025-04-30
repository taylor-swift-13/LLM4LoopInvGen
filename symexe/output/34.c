
/*@Inv
  (\at(n, Pre) > 0 ==> (((x == n@pre) && (v3 == v3@pre) && (v2 == v2@pre) && (v1 == v1@pre) && (n == n@pre)) || (x == n@pre - (n - x))) &&
  !(\at(n, Pre) > 0 ==> ((x == n@pre) && (v3 == v3@pre) && (v2 == v2@pre) && (v1 == v1@pre) && (n == n@pre)) &&
  v3 == v3@pre &&
  v2 == v2@pre &&
  v1 == v1@pre &&
  n == n@pre
*/
while (x > 0) {
    x = x - 1;
}
