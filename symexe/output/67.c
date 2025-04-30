
/*@Inv
  (1 <= n) => (x >= 1 && x <= n + 1) &&
  n == n@pre &&
  (1 <= n) => (y >= 0)
*/
while (x <= n) {
    y = n - x;
    x = x + 1;
}

/*@ assert (n > 0) ==> (y >= 0); */
