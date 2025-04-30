
/*@Inv
  (\at(n, Pre) > 1) ==> (((x == n@pre) && (v3 == v3@pre) && (v2 == v2@pre) && (v1 == v1@pre) && (n == n@pre)) || (x == 1)) &&
  (!(\at(n, Pre) > 1)) ==> ((x == n@pre) && (v3 == v3@pre) && (v2 == v2@pre) && (v1 == v1@pre) && (n == n@pre)) &&
  v3 == v3@pre &&
  v2 == v2@pre &&
  v1 == v1@pre &&
  n == n@pre
*/
