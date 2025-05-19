int unknown();
void foo(int v1,int v2,int v3)  
/*@ Require emp 
   Ensure emp
*/ 
    {

    int sn = 0;
    int x = 0;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (unknown()) {
  
      x  = (x + 1);
      sn  = (sn + 1);
      
    }
    /*@  (sn != x) => (sn == -1)*/
  
  }