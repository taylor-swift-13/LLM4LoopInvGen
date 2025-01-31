void foo(int n,int z1,int z2,int z3)
/*@  Require emp
     Ensure emp
*/
{
    int x = 1;
    int m = 1;
    
    
    while (x < n) {
        m = x;
        x = x + 1;
    }
 
    if(n > 1){
    /*@  (m <= n) && (m >= 1) */
  }
}