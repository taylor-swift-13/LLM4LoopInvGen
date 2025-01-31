
void foo(int n)
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