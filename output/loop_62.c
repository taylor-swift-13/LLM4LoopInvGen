void foo(int y,int z1,int z2,int z3)
/*@  Require emp
     Ensure emp
*/ {

  int x = 1;
  
  
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv
        z3 == z3@pre 
    &&  z2 == z2@pre 
    &&  z1 == z1@pre 
    &&  y == y@pre 
    &&  x >= 1 
    &&  x <= y 
*/
while (x < y) {
    x = x + x;
}


  /*@  x >= 1 */

}