
/*@Inv
  (1 <= n@pre) ==> (((x == 1) && (y == y@pre) && (n == n@pre)) || (1 <= x <= n + 1)) &&
  (1 <= n@pre) ==> (((x == 1) && (y == y@pre) && (n == n@pre)) || (y == n - x)) &&
  !(1 <= n@pre) ==> ((x == 1) && (y == y@pre) && (n == n@pre)) &&
  n == n@pre
*/
