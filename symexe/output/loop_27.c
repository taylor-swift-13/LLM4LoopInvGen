void foo()
/*@  Require emp
     Ensure emp
*/ {
    int x = 1;
    int y = 10;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (x <= 10) {
        y = 10 - x;
        x = x +1;
    }

    /*@ (y >= 0) && (y < 10) */

}