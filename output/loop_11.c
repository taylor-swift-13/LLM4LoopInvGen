void foo(int n)
{
    int x = 0;
    int m = 0;

    
    
/*@
  loop invariant (0 < \at(n, Pre)) ==> ( (m == 0) || (m == x - 1) );
  loop invariant (0 < \at(n, Pre)) ==> ( x >= 0 && x <= n );
  loop invariant n == \at(n, Pre);
*/
while (x < n) {
    m = x;
    x = x + 1;
}


    /*@ assert (n > 0) ==> ((m <= n) && (m >= 0)); */

}