void foo(int n)
/*@  Require emp
     Ensure emp
*/
{
    int x = 0;
    int m = 0;

    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (x < n) {
        m = x;
        x = x + 1;
    }



  if(n > 0){
    /*@  (m <= n) && (m >= 0) */
  }

}