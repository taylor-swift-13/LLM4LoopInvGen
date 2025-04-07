void foo(int x, int y,int z1,int z2,int z3)  
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
  
    /*@  (i == j) => (y == 0) */
  
  }