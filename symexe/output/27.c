void foo(int n)  
/*@ Require emp 
   Ensure emp
*/ 
    {

    int x = n;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (x > 1) {
      
       x  = x - 1;
  
    }
  
   /*@  (n >= 1) => (x == 1) */
  }