void foo(int x, int y)  
/*@ Require emp 
   Ensure emp
*/ 
    {

    int i = x;
    int j = y;
    
    
    while (x != 0) {
  
      x  = x - 1;
      y  = y - 1;
  
    }
  
    /*@  (y != 0) => (i != j) */
  
  }