
/*@Inv
  (x == 0) && (sn == 0) && (v3 == v3@pre) && (v2 == v2@pre) && (v1 == v1@pre) ||
  sn == x &&
  x == 0 &&
  sn == 0 &&
  v3 == v3@pre &&
  v2 == v2@pre &&
  v1 == v1@pre
*/
while (1) {
    x  = (x + 1);
    sn  = (sn + 1);
  
    /*@ assert (sn != -1) ==> (sn == x);*/
}
