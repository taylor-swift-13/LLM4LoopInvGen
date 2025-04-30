
/*@Inv
  (\at(n, Pre) > 0) => (x == n@pre) &&
  !(\at(n, Pre) > 0) => (x == n@pre && n <= 0) &&
  v3 == v3@pre &&
  v2 == v2@pre &&
  v1 == v1@pre &&
  n == n@pre
*/
while (x > 0) {
    x = x - 1;
}

/*@ assert (x != 0) ==> (n < 0); */
