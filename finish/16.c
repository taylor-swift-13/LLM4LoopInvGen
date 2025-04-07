void foo(int n)
{
    int x = 0;
    int m = 0;

    
    while (x < n) {
        
        if (1) {
            m = x;
        }
        
        x = x + 1;
    }

    /*@ assert (n > 0) ==> (m >= 0); */

}