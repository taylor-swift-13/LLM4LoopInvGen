void foo(int n)  
/*@ Require emp 
   Ensure emp
*/ 
    {

    int x = n;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((n@pre > 0) => (x >= 0 && x <= n@pre)) &&
((!(n@pre > 0)) => ((x == n@pre)&&(n == n@pre))) &&
(n == n@pre)
    */
    
    while (x > 0) {
        x = x - 1;
    }
  
   /*@  (n >= 0) => (x == 0) */
  }