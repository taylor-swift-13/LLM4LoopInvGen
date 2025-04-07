void foo(int n,int v1,int v2,int v3)  
/*@ Require emp 
   Ensure emp
*/ 
    {

    int i = 1;
    int sn = 0;
    
    
    while (i <= n) {
      
      i  = (i + 1);
      sn  = (sn + 1);
  
    }
    
    /*@  (sn!= n) => (sn ==0) */
  
  }