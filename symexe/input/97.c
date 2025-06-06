void foo(int x)  
/*@ Require emp 
   Ensure emp
*/ 
    {
    int i =0;
    int j =0;
    int y =2;
    
    
    while (i <= x) {
      
      i  = i + 1;
      j  = j + y;
  
    }
  
  /*@  (y == 1) => (i == j) */
  
  }