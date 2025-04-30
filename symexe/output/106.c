
/*@Inv
  (\at(a, Pre) <= \at(m, Pre) && \at(j, Pre) < 1) ==> (((k == 0) && (a == a@pre) && (j == j@pre) && (m == m@pre)) || (PLACE_HOLDER_m)) &&
  (\at(a, Pre) <= \at(m, Pre) && \at(j, Pre) < 1) ==> (((k == 0) && (a == a@pre) && (j == j@pre) && (m == m@pre)) || (PLACE_HOLDER_k)) &&
  (\at(a, Pre) <= \at(m, Pre) && \at(j, Pre) < 1) ==> (a == a@pre) &&
  (\at(a, Pre) <= \at(m, Pre) && \at(j, Pre) < 1) ==> (j == j@pre)
*/
while ( k < 1) {
    if(m < a) {
        m = a;
    }
    k = k + 1;
}
