void foo()  
/*@ Require emp 
   Ensure emp
*/ 
    {

    int x = 1;
    int y = 0;
  
    
    while (y < 1000) {
      
       x  = x + y;
       y  = y + 1;
      
    }
    
    /*@  x >= y */
  }