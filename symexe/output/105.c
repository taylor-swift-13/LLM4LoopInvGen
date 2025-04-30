
/*@Inv
  (0 < n@pre) ==> (((x < n) && (v3@pre == v3@pre) && (v2@pre == v2@pre) && (v1@pre == v1@pre) && (n@pre == n@pre)) || (x < n)) &&
  !(0 < n@pre) ==> ((x == 0) && (v3@pre == v3@pre) && (v2@pre == v2@pre) && (v1@pre == v1@pre) && (n@pre == n@pre)) &&
  v3@pre == v3@pre &&
  v2@pre == v2@pre &&
  v1@pre == v1@pre &&
  n@pre == n@pre
*/
