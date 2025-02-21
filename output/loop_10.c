
void foo(int x,int y,int z1,int z2,int z3)
/*@  Require x >= 0 && x <= 2 && y <= 2 && y >= 0
     Ensure emp
*/ {

  
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv
    z3 == z3@pre 
    && z2 == z2@pre 
    && z1 == z1@pre 
    && x >= 0 
    && y >= 0 
    && (x - y) == (x@pre - y@pre) 
    && ((x - x@pre) % 2 == 0) 
    && ((y - y@pre) % 2 == 0)
*/
while (1) {
    x = x + 2;
    y = y + 2;

    if (x == 4) {
        /*@ (y != 0) */
    }
}




}