
void foo(int n)
/*@  Require n >= 0
     Ensure emp
*/ {

  int x = n;
  int y = 0;

 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (x > 0) {
    
    y  = y + 1;
    x  = x - 1;
    
  }
 /*@  y == n  */
}