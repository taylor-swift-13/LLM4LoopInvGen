int unknown();
void foo(int n)
/*@ Require emp 
   Ensure emp
*/ 
    {
    int x = 1;
    int m = 1;

    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((1 < n@pre) => (((m == 1)&&(x == 1)&&(n == n@pre)) || (m < n))) &&
((1 < n@pre) => (((m == 1)&&(x == 1)&&(n == n@pre)) || (x <= n))) &&
((!(1 < n@pre)) => ((m == 1)&&(x == 1)&&(n == n@pre))) &&
(n == n@pre)
    */
    
    while (x < n) {

        if (unknown()) {
            m = x;
        }

        x = x + 1;
    }
 
    /*@  (n > 1) => (m >= 1) */

}