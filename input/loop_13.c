void foo(int n,int z1,int z2,int z3)
{
    int x = 0;
    int m = 0;

    
    while (x < n) {
        m = x;
        x = x + 1;
    }

    /*@ assert (n > 0) ==> ((m <= n) && (m >= 0)); */

}