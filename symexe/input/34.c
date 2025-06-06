void foo(int n,int v1,int v2,int v3)  
/*@ Require emp 
   Ensure emp
*/ 
    {

    int x = n;
    
    
    while (x > 0) {
      
       x  = x - 1;
  
    }
  
   /*@  (n >= 0) => (x == 0) */
  }