int unknown();
void foo(int n,int z1,int z2,int z3)
 
/*@ Require emp 
   Ensure emp
*/ 
    {
    int x = 0;
    int m = 0;

    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < n@pre) => (((m == 0) && (x == 0) && (z3 == z3@pre) && (z2 == z2@pre) && (z1 == z1@pre) && (n == n@pre)) || (m <= x && x <= n && (m == 0 || (0 <= m && m < n))))) &&
((0 < n@pre) => (((m == 0) && (x == 0) && (z3 == z3@pre) && (z2 == z2@pre) && (z1 == z1@pre) && (n == n@pre)) || (m <= x && x <= n && (m == 0 || (0 <= m && m < n))))) &&
((!(0 < n@pre)) => ((m == 0) && (x == 0) && (z3 == z3@pre) && (z2 == z2@pre) && (z1 == z1@pre) && (n == n@pre))) &&
(z3 == z3@pre) &&
(z2 == z2@pre) &&
(z1 == z1@pre) &&
(n == n@pre)
    */
    
    while (x < n) {
        if (unknown()) {
            m = x;
        }
        x = x + 1;
    }

    /*@  (n > 0) => (m < n) */

}