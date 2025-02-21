
void foo(int x, int y,int z1,int z2,int z3)
/*@  Require x >= 0 && x <= 10 && y <= 10 && y >= 0
     Ensure emp
*/ {
  
  
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv   
    z3 == z3@pre && z2 == z2@pre && z1 == z1@pre &&
    x >= 0 && y >= 0 &&
    x == x@pre + 10 * (x - x@pre) / 10 && y == y@pre + 10 * (x - x@pre) / 10 &&
    (x - x@pre) % 10 == 0
*/ 
while (1) {
    
    x = x + 10;
    y = y + 10;

    if (x == 20) {
        /*@ (y != 0) */
    }
    
}



}
