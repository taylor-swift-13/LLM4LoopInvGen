
void foo()
/*@  Require emp
     Ensure emp
*/ {

  int x = 1;
  int y = 0;

  
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv
    (y >= 0) && (y <= 1000) &&
    (x == (y * (y + 1)) / 2 + 1)
*/
while (y < 1000) {
    
     x  = x + y;
     y  = y + 1;
    
}

  
  /*@ x >= y */
}
