int unknown();



void foo(int n)  
/*@ Require n > 0 
   Ensure emp
*/ 
  {

  int i, a, b;
  i = 0; a = 0; b = 0;
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while( i < n ) {
    if(unknown()) {
      a = a + 1;
      b = b + 2;
    } else {
      a = a + 2;
      b = b + 1;
    }
    i = i + 1;
  }
  /*@  a + b == 3*n  */
}
