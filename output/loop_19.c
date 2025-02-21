void foo(int n)
/*@  Require emp
     Ensure emp
*/ {

  int x = n;
  
  
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv
    n == n@pre 
    && x >= 0 
    && x <= n@pre
*/
while (x > 0) {
    x = x - 1;
}

  
   if (n >= 0){
    /*@ (x == 0) */
  }
}