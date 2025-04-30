
/*@Inv
  (x == 0) && (sn == 0) && (v3 == v3@pre) && (v2 == v2@pre) && (v1 == v1@pre) ||
  sn == 0
*/
while (1) {
    x  = (x + 1);
    sn  = (sn + 1);
  
    /*@ assert (sn != x) ==> (sn == -1);*/
}
