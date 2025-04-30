
/*@Inv
  (n@pre >= 0) => ((0 < n@pre) => (0 <= x && x <= n)) &&
  (n@pre >= 0) => (!(0 < n@pre) => ((x == 0) && (n == n@pre))) &&
  (n@pre >= 0) => (n == n@pre)
*/
while (x < n) {
    x = x + 1;
}

/*@ assert x == n; */
