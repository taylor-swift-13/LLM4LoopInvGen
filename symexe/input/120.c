
void foo()  
/*@ Require emp 
   Ensure emp
*/ 
    {
 
    int i = 1;
    int sn = 0;
    
     
    while (i <= 8) {
  
      i  = (i + 1);
      sn  = (sn + 1);
      
    }
  
    /*@  (sn != 8) => (sn == 0)*/
  
  }