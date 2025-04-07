void foo(int n)  
/*@ Require emp 
   Ensure emp
*/ 
    {

    int x = n;
    
    
    while (x > 0) {
      
       x  = x - 1;
  
    }
  
   /*@  (x != 0) => (n < 0) */
  }