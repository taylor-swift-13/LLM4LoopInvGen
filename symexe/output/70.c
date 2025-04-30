
/*@Inv
  (1 <= n@pre) ==> (((x == 1) && (v3 == v3@pre) && (v2 == v2@pre) && (v1 == v1@pre) && (y == y@pre) && (n == n@pre)) || (0 <= y && y <= n)) &&
  (1 <= n@pre) ==> (((x == 1) && (v3 == v3@pre) && (v2 == v2@pre) && (v1 == v1@pre) && (y == y@pre) && (n == n@pre)) || (x <= n)) &&
  !(1 <= n@pre) ==> ((x == 1) && (v3 == v3@pre) && (v2 == v2@pre) && (v1 == v1@pre) && (y == y@pre) && (n == n@pre)) &&
  v3 == v3@pre &&
  v2 == v2@pre &&
  v1 == v1@pre &&
  n == n@pre
*/
