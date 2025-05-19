int unknown();
void foo(int n,int z1,int z2,int z3)
 
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


    /*@  (n > 1) => (m < n) */

}