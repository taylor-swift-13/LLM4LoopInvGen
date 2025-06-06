
void foo(int n)  
/*@ Require n > 0
    Ensure emp
*/ 
    {
  int x= 0;
  
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while(x<n) {
    x++;
  } 
  /*@  (n > 0) => (x == n) */
 
}
