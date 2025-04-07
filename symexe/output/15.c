int unknown();
void foo(int n)
 
/*@ Require emp 
   Ensure emp
*/ 
    {
    int x = 0;
    int m = 0;

    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (x < n) {

        if (unknown()) {
            m = x;
        }
        
        x = x + 1;
    }

    /*@  (n > 0) => (m < n) */

}