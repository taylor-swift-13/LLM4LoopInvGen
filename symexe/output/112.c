
/*@Inv
  (1 <= n@pre) ==> ((sn == 0) && (i == 1) && (v3 == v3@pre) && (v2 == v2@pre) && (v1 == v1@pre) && (n == n@pre) || (PLACE_HOLDER_i)) &&
  (1 <= n@pre) ==> ((sn == 0) && (i == 1) && (v3 == v3@pre) && (v2 == v2@pre) && (v1 == v1@pre) && (n == n@pre) || (PLACE_HOLDER_sn)) &&
  !(1 <= n@pre) ==> (sn == 0 && i == 1 && v3 == v3@pre && v2 == v2@pre && v1 == v1@pre && n == n@pre) &&
  v3 == v3@pre &&
  v2 == v2@pre &&
  v1 == v1@pre &&
  n == n@pre
*/
while (i <= n) {
    i = (i + 1);
    sn = (sn + 1);
}
