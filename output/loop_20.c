void foo()
/*@  Require emp
     Ensure emp
*/ {
  int x = 100;
  
  
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv 
    x >= 0 
    && x <= 100 
    && x == 100 - (100 - x)
*/
while (x > 0) {
    x = x - 1;
}


  /*@ x == 0 */
}