void foo(int n) {

    int i = 1;
    int sn = 0;
    
    
    
/*@
  loop invariant (1 <= n) ==> (1 <= i <= n + 1);
  loop invariant (1 <= n) ==> (sn == i - 1);
  loop invariant (!(1 <= n)) ==> (i == 1 && sn == 0);
  loop invariant n == \at(n, Pre);
*/
while (i <= n) {
    i = i + 1;
    sn = sn + 1;
}

    
    /*@ assert (sn!= n) ==> (sn ==0); */
  
  }