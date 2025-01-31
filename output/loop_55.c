void foo(int v1,int v2,int v3) {

  int sn = 0;
  int x = 0;
  
  
  
/*@
  loop invariant (1) ==> (x >= 0);
  loop invariant (1) ==> (sn >= 0);
  loop invariant v3 == \at(v3, Pre);
  loop invariant v2 == \at(v2, Pre);
  loop invariant v1 == \at(v1, Pre);
*/
while (1) {

  x  = (x + 1);
  sn  = (sn + 1);

  if(sn != x){
    /*@  assert (sn == -1); */
  }

}


}