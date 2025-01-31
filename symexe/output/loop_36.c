void foo(int y)
/*@  Require emp
     Ensure emp
*/ {

  int x = -50;

  
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (x < 0) {
    
    x  = x + y;
    y  = y + 1;
    

  }
  /*@ y > 0 */

}