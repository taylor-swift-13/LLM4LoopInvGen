void foo(int n)  
/*@ Require n >= 1
   Ensure empty
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