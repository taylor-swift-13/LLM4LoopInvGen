void foo() 
/*@ Require emp 
   Ensure emp
*/ 
    {
  
    int x = 1;
    int y = 0;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (((y == 0)&&(x == 1)) || (x == 1 + (y * (y - 1)) / 2)) &&
(((y == 0)&&(x == 1)) || (y >= 0 && y <= 100000))
    */
    
    while (y < 100000) {
      
       x  = x + y;
       y  = y + 1;
    }
  
    /*@  x >= y */
  }