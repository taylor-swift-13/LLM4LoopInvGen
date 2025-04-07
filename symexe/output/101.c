
void foo(int n)  
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
    /*@  (x != n) => (n < 0) */
    
  }