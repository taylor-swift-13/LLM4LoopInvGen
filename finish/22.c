void foo(int n,int z1,int z2,int z3)
{
    int x = 1;
    int m = 1;

    
    while (x < n) {

        if (1) {
            m = x;
        }
        
        x = x + 1;
    }

    /*@ assert (n > 0) ==> (m >= 1); */

}