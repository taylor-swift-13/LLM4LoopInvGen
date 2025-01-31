
void foo(int n)
{
    int x = 1;
    int m = 1;
    
    
    
    /*@
      loop invariant (1 < \at(n, Pre)) ==> ( (m == 1)|| (1 <= m && m < x) );
      loop invariant (1 < \at(n, Pre)) ==> ( 1 <= x && x <= n );
      loop invariant n == \at(n, Pre);
    */
    while (x < n) {
        m = x;
        x = x + 1;
    }

 
    /*@ assert (n > 1) ==> ((m <= n) && (m >= 1)); */

}