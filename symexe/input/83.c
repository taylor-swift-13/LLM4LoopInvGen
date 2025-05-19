void foo(int y)  
/*@ Require emp 
   Ensure emp
*/ 
    {

    int x = -5000;
  
    
    while (x < 0) {
      
      x  = x + y;
      y  = y + 1;
      
  
    }
    /*@  y > 0 */
  
  }