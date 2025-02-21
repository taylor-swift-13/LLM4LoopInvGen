
void foo(int n, int z1, int z2, int z3)
/*@  Require emp
     Ensure emp
*/
{
    int x = 0;
    int m = 0;

  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv
    z3 == z3@pre 
    && z2 == z2@pre 
    && z1 == z1@pre 
    && n == n@pre 
    && x >= 0 
    && x <= n 
    && m == x - 1
    && (x == 0 ? m == 0 : m == x - 1)
*/
while (x < n) {
    m = x;
    x = x + 1;
}


    if(n > 0){
    /*@  (m <= n) && (m >= 0) */
  }

}
