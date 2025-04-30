
/*@Inv
  ((i == 0) && (t == t@pre) && (c == c@pre) && (j == j@pre)) ||
  (j == i + i) &&
  ((i == 0) && (t == t@pre) && (c == c@pre) && (j == j@pre)) ||
  (t == c - 48) &&
  ((i == 0) && (t == t@pre) && (c == c@pre) && (j == j@pre)) ||
  (i == j + t) &&
  c == c@pre
*/
while(1) {
    if(c > 48) {
        if (c < 57) {
            j = i + i;
            t = c - 48;
            i = j + t;
        }
    }
    /*@ assert i >= 0; */
}
