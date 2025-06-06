void foo(int x, int y)  
/*@ Require emp 
   Ensure emp
*/ 
    {

    int i = x;
    int j = y;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (x != 0) {
  
      x  = x - 1;
      y  = y - 1;
  
    }
  
    /*@  (y != 0) => (i != j) */
  
  }