
/*@Inv
  (0 < n@pre) ==> ((x == 0) && (v3 == v3@pre) && (v2 == v2@pre) && (v1 == v1@pre) && (n == n@pre) || (PLACE_HOLDER_x)) &&
  !(0 < n@pre) ==> (x == 0) && (v3 == v3@pre) && (v2 == v2@pre) && (v1 == v1@pre) && (n == n@pre) &&
  v3 == v3@pre &&
  v2 == v2@pre &&
  v1 == v1@pre &&
  n == n@pre
*/
while (x < n) {
    x = (x + 1);
}
