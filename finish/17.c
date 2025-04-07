void foo(int n)
{
    int x = 1;
    int m = 1;
    
    
    while (x < n) {
        
        if (1) {
            m = x;
        }
        
        x = x + 1;
    }
 
    /*@ assert (n > 1) ==> (m < n); */

}