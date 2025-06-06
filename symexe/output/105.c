void foo(int n,int v1,int v2,int v3)  
/*@ Require emp 
   Ensure emp
*/ 
    {
  
    int x = 0;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (x < n) {
      
      x  = (x + 1);
      
    }
    /*@  (n >= 0) => (x == n) */
    
  }