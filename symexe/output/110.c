void foo(int n)  
/*@ Require emp 
   Ensure emp
*/ 
    {

    int i = 1;
    int sn = 0;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (i <= n) {
      
      i  = (i + 1);
      sn  = (sn + 1);
  
    }
    
    /*@  (sn!= n) => (sn ==0) */
  
  }