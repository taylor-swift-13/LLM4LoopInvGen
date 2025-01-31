
void foo(int n) {

  int i = 1;
  int sn = 0;
  
  
  
  /*@
    loop invariant (1 <= \at(n, Pre)) ==> (sn == i - 1);
    loop invariant (1 <= \at(n, Pre)) ==> (1 <= i && i <= n + 1);
    loop invariant n == \at(n, Pre);
  */
  while (i <= n) {
    
    i  = (i + 1);
    sn  = (sn + 1);

  }

  
  /*@ assert ( sn!= 0) ==> (sn ==n)*/

}