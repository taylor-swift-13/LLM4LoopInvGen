void foo(int n,int z1,int z2,int z3)
{
    int x = 1;
    int m = 1;
    
    
    
    /*@
      loop invariant (1 < \at(n, Pre)) ==> ( (m == 1) || (m < x && m >= 1) );
      loop invariant (1 < \at(n, Pre)) ==> (x <= n && x >= 1);
      loop invariant z3 == \at(z3, Pre);
      loop invariant z2 == \at(z2, Pre);
      loop invariant z1 == \at(z1, Pre);
      loop invariant n == \at(n, Pre);
    */
    while (x < n) {
        m = x;
        x = x + 1;
    }

 
    /*@ assert (n > 1) ==> ((m <= n) && (m >= 1)); */

}