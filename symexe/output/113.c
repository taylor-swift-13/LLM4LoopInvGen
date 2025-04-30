
/*@Inv
  (1 <= n@pre) ==> ((sn == 0 && i == 1 && v3@pre == v3 && v2@pre == v2 && v1@pre == v1 && n@pre == n) || (sn == i - 1)) &&
  (1 <= n@pre) ==> ((sn == 0 && i == 1 && v3@pre == v3 && v2@pre == v2 && v1@pre == v1 && n@pre == n) || (sn == i - 1)) &&
  !(1 <= n@pre) ==> (sn == 0 && i == 1 && v3@pre == v3 && v2@pre == v2 && v1@pre == v1 && n@pre == n) &&
  v3@pre == v3 &&
  v2@pre == v2 &&
  v1@pre == v1 &&
  n@pre == n
*/
