

void foo(int n, int k)  
/*@ Require n > 0 && k > n 
   Ensure emp
*/ 
    {

  int j = 0;

 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while( j < n ) {
    j++;
    k--;
  } 
  /*@  k>=0 */
}