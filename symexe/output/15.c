
/*@Inv
  (0 < n@pre) => ((m == 0 && x == 0 && n@pre) || (x == m + 1)) &&
  (0 < n@pre) => ((m == 0 && x == 0 && n@pre) || (m == x - 1)) &&
  !(0 < n@pre) => (m == 0 && x == 0 && n@pre) &&
  n == n@pre
*/
