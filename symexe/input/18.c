int unknown();
void foo(int n)
/*@ Require emp 
   Ensure emp
*/ 
    {
    int x = 1;
    int m = 1;

    
    while (x < n) {

        if (unknown()) {
            m = x;
        }
        
        x = x + 1;
    }
 
    /*@  (n > 1) => (m >= 1) */

}