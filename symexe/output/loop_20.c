void foo()
/*@  Require emp
     Ensure emp
*/ {
  int x = 100;
  
  
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (x > 0) {
    
    x  = x - 1;
    
  }

  /*@ x == 0 */
}