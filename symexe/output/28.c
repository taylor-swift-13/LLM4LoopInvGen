void foo(int n)  
/*@ Require emp 
   Ensure emp
*/ 
    {

    int x = n;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (x > 0) {
      
       x  = x - 1;
  
    }
  
   /*@  (x != 0) => (n < 0) */
  }