int unknown();
void foo(int n)
/*@ Require emp 
   Ensure emp
*/ 
    {
    int x = 1;
    int m = 1;

    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (x < n) {

        if (unknown()) {
            m = x;
        }
        
        x = x + 1;
    }
 
    /*@  (n > 1) => (m >= 1) */

}