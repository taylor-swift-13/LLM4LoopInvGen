int unknown()
/*@ Require emp 
   Ensure __return <= INT_MAX && __return > INT_MIN
*/;

void foo(int n)  
/*@ Require n > 0
   Ensure emp
*/ 
    {
  int x = 0;
  int m = 0;
 
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((n@pre > 0) => ((0 < n@pre) => (((m == 0)&&(x == 0)&&(n == n@pre)) || (0 <= m && m < x))) ) &&
((n@pre > 0) => ((0 < n@pre) => (((m == 0)&&(x == 0)&&(n == n@pre)) || (0 <= x && x <= n))) ) &&
((n@pre > 0) => ((!(0 < n@pre)) => ((m == 0)&&(x == 0)&&(n == n@pre)))) &&
((n@pre > 0) => (n == n@pre))
    */
    
                while (x < n) {
    if (unknown()) {
      m = x;
    }
    x = x + 1;
  }
  /*@  (n > 0) => (0 <= m && m < n) */
}