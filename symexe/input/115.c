int unknown();
void foo()  
/*@ Require emp 
   Ensure emp
*/ 
    {

    int sn = 0;
    int x = 0;
    
    
    while (unknown()) {
  
      x  = (x + 1);
      sn  = (sn + 1);
  
      
    }
  
    /*@  (sn != -1) => (sn == x)*/
  }