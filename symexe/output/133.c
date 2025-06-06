
void foo(int n)  
/*@ Require n >=0
   Ensure emp
*/ 
    {

    int x = 0;
    int x0;
  
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < n@pre) => (((x == 0)&&(n == n@pre)) || (x <= n))) &&
((!(0 < n@pre)) => ((x == 0)&&(n == n@pre))) &&
(n == n@pre)
    */
    
                while (x < n) {
      {
       x  = x + 1;
      }
  
    }
    /*@  x == n */
  
  }