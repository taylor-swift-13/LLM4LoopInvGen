void foo()
/*@  Require emp
     Ensure emp
*/ {
  int x = 10000;
  
  
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv 
    x >= 0 
    && x <= 10000 
    && (x + 1) >= 1 
    && (x + 1) <= 10001
*/ 
while (x > 0) {
    x = x - 1;
}


  /*@ x == 0 */
}