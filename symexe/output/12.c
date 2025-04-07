int unknown();

void foo(int x, int y,int z1,int z2,int z3)  
/*@ Require  x >= 0 && x <= 10 && y <= 10 && y >= 0
   Ensure emp
*/ 
    {
  
  
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (unknown()) {
      
        x = x + 10;
        y = y + 10;
      
    }

    /*@  (y == 0) =>  (x != 20) */
  
   
  }