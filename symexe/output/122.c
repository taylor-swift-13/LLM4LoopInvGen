void foo(int size,int v1,int v2,int v3)  
/*@ Require emp 
   Ensure emp
*/ 
    {
 
    int i = 1;
    int sn = 0;
    
     
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (i <= size) {
  
      i  = (i + 1);
      sn  = (sn + 1);
      
    }
  
    /*@  (sn != size) => (sn == 0)*/
  
  }