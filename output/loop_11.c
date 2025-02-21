
void foo(int n)
/*@  Require emp
     Ensure emp
*/
{
    int x = 0;
    int m = 0;

    
   
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv   
    n == n@pre 
    && x >= 0 
    && x <= n 
    && m >= 0 
    && m < n 
    && (x == 0 => m == 0) 
    && (x > 0 => m == x - 1)
    && (x < n => m == x)
*/ 
while (x < n) {
    m = x;
    x = x + 1;
}




  if(n > 0){
    /*@  (m <= n) && (m >= 0) */
  }

}
