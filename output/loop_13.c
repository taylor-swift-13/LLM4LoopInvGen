void foo(int n,int z1,int z2,int z3)
{
    int x = 0;
    int m = 0;

    
    
    /*@
      loop invariant (0 < \at(n, Pre)) ==> ( (m == 0)|| m == x - 1 );
      loop invariant (0 < \at(n, Pre)) ==> ( x >= 0 && x <= n );
      loop invariant z3 == \at(z3, Pre);
      loop invariant z2 == \at(z2, Pre);
      loop invariant z1 == \at(z1, Pre);
      loop invariant n == \at(n, Pre);
    */
    while (x < n) {
        m = x;
        x = x + 1;
    }


    /*@ assert (n > 0) ==> ((m <= n) && (m >= 0)); */

}