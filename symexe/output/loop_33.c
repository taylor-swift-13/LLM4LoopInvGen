
void foo(int x, int y)
/*@  Require x >= y  && y >= 0
     Ensure emp
*/ {

  int i = 0;
  

  
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (1) {
    if ( i < y )
    {
    i  = (i + 1);
    /*@  (i >= 0 && i < x ) */
    }
  }



 
}