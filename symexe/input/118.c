
void foo(int size)  
/*@ Require emp 
   Ensure emp
*/ 
    {
 
    int i = 1;
    int sn = 0;
    
     
    while (i <= size) {
  
      i  = (i + 1);
      sn  = (sn + 1);
      
    }
  
    /*@  (sn != size) => (sn == 0)*/
  
  }