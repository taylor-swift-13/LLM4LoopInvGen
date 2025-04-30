
/*@Inv
  (0 < c@pre) => (((0 <= k) && (k < c@pre) && (m >= m@pre)) || (m >= a)) &&
  c == c@pre &&
  a == a@pre &&
  j == j@pre &&
  (0 < c@pre) => (m >= m@pre)
*/

while (k < c) {

    if (m < a) {
        m = a;
    }
    
    k = k + 1;
}

/*@ assert (c > 0) => (a <= m); */
