
void foo(int n)  
/*@ Require emp 
   Ensure emp
*/ 
    {
  
    int x = 0;
    
    
    while (x < n) {
      
      x  = (x + 1);
      
    }
    /*@  (x != n) => (n < 0) */
    
  }