
void foo(int n)
/*@  Require emp
     Ensure emp
*/
{
    int x = 1;
    int m = 1;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv
        n == n@pre
        && x >= 1
        && x <= n
        && (m == x - 1 || x == 1)
*/ 
while (x < n) {
    m = x;
    x = x + 1;
}


    if(n > 1){
    /*@  (m <= n) && (m >= 1) */
  }

}