
void foo(int y,int z1,int z2,int z3)
/*@  Require emp
     Ensure emp
*/ {

  int x = -50;

  
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv
    z3 == z3@pre && z2 == z2@pre && z1 == z1@pre 
    && x <= -50 + y * (y-1) / 2 && x >= -50 && y >= y@pre
*/
while (x < 0) {
    x = x + y;
    y = y + 1;
}

  /*@  y > 0 */

}
