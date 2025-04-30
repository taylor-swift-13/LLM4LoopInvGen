
/*@Inv
  (x == 0 && sn == 0) || (sn == x - 1) &&
  (x == 0 && sn == 0) || (x > 0)
*/
while (1) {
    x  = (x + 1);
    sn  = (sn + 1);
    /*@ assert (sn != x) ==> (sn == -1);*/
}
