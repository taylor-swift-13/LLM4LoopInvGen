
void foo(int n)
/*@  Require emp
     Ensure emp
*/ {
  
  int x = 0;
  
  
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv
    n == n@pre 
    && x >= 0 
    && x <= n 
*/
while (x < n) {
    x = (x + 1);
}

  
  if( n>=0 ){
  /*@   (x == n) */
  }
  
}