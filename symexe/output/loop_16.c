void foo()
/*@  Require emp
     Ensure emp
*/ {
  
  int i=1;
  int j=10;
 
  
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (j >= i) {
    
    i  = i + 2;
    j  = j - 1;
    

  }

  /*@ j == 6 */

}