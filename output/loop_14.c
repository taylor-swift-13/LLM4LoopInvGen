void foo(int n,int z1,int z2,int z3)
/*@  Require emp
     Ensure emp
*/
{
    int x = 1;
    int m = 1;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv
    z3 == z3@pre 
    && z2 == z2@pre 
    && z1 == z1@pre 
    && n == n@pre 
    && x >= 1 
    && x <= n 
    && m >= 1 
    && m <= x 
*/ 
while (x < n) {
    m = x;
    x = x + 1;
}

 
    if(n > 1){
    /*@  (m <= n) && (m >= 1) */
  }
}