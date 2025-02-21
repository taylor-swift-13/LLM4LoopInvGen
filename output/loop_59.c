void foo(int x, int y)
/*@  Require emp
     Ensure emp
*/ {

  int i = x;
  int j = y;
  
  
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv 
        j == y@pre 
        && i == x@pre 
        && x >= 0 
        && y == j - (x@pre - x) 
*/
while (x != 0) {

    x  = x - 1;
    y  = y - 1;

}

  
  if(i == j){
  /*@  (y == 0) */
  }

}