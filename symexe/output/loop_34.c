
void foo(int x, int y,int z1,int z2,int z3)
/*@  Require x >= y  && y >= 0
     Ensure emp
*/ {

  int i = 0;
  

  
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (unkown()) {
    if ( i < y )
    {
    i  = (i + 1);
    /*@  (i >= 0 && i < x ) */
    }
  }


 
}