
void foo(int n)
/*@  Require n >= 0
     Ensure emp
*/ {

  int x = 0;
  int x0;

  
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv
    n == n@pre 
    && 0 <= x 
    && x <= n
*/ 
while (x < n) {
    {
     x  = x + 1;
    }
}

  /*@ x == n */

}