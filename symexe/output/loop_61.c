void foo(int y)
/*@  Require emp
     Ensure emp
*/ {

  int x = 1;
  
  
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (x < y) {

     x  = x + x;
     
  }

  /*@  x >= 1 */

}