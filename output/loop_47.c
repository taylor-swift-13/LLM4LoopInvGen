void foo()
/*@  Require emp
     Ensure emp
*/ {

  int x = 0 ;
  
  
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv 
    x >= 0 
    && x <= 100 
*/
while (x < 100) {
    x = (x + 1);
}

  
 /*@  x == 100  */
}