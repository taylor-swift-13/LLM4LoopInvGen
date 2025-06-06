void foo(int n)  
/*@ Require emp 
   Ensure emp
*/ 
    {

    int x = n;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((n@pre > 1) => (((x == n@pre)&&(n == n@pre)) || (x >= 1))) &&
((!(n@pre > 1)) => ((x == n@pre)&&(n == n@pre))) &&
(n == n@pre)
    */
    
    while (x > 1) {
        x = x - 1;
    }
  
   /*@  (x != 1) => (n < 1) */
  }