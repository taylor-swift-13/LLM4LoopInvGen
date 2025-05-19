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
 
  while (x < n) {
    if (unknown()) {
      m = x;
    }
    x = x + 1;
  }
  /*@  (n > 0) => (0 <= m && m < n) */
}