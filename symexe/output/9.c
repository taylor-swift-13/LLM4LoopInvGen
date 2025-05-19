int unknown();

void foo(int x,int y)  
/*@ Require x >= 0 && x <= 2 && y <= 2 && y >= 0
   Ensure emp
*/ 
    {

  
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (unknown()) {
      
      x  = x + 2;
      y  = y + 2;

  
    }
    /*@  (x == 4) => (y != 0)  */

   
  
  }