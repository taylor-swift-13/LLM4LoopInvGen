void foo() {

  int sn = 0;
  int x = 0;
  
  
  
/*@
  loop invariant (1) ==> (x == \at(x, Pre) + sn);
  loop invariant (1) ==> (sn == \at(sn, Pre) + x);
*/
while (1) {

    x  = (x + 1);
    sn  = (sn + 1);

    if(sn != x){
    /*@ assert (sn == -1); */
    }

}


}