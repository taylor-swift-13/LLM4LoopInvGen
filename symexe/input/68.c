void foo(int n,int y)  
/*@ Require emp 
   Ensure emp
*/ 
    {
    
    int x = 1;

    
    while (x <= n) {
        y = n - x;
        x = x + 1;
    }

    /*@  (n > 0) => (y <= n) */


}