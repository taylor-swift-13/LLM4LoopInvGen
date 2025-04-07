void foo(int n) {

    int x = n;
    
    
    
/*@
  loop invariant (\at(n, Pre) > 1) ==> (((x == \at(n, Pre)) && (n == \at(n, Pre))) || (x >= 1 && x < \at(n, Pre)));
  loop invariant (!(\at(n, Pre) > 1)) ==> ((x == \at(n, Pre)) && (n == \at(n, Pre)));
  loop invariant n == \at(n, Pre);
*/
while (x > 1) {
    x = x - 1;
}

  
   /*@ assert (n >= 1) ==> (x == 1); */
  }