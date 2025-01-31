
void foo(int n)
/*@  Require emp
     Ensure emp
*/
{
    int x = 1;
    int m = 1;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (x < n) {
        m = x;
        x = x + 1;
    }

    if(n > 1){
    /*@  (m <= n) && (m >= 1) */
  }

}