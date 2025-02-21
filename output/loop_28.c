
void foo(int y)
/*@  Require emp
     Ensure emp
*/ {
    int x = 1;

    

    
   
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv
    (x >= 1) && (x <= 101) && (y == 100 - x + 1) && (y@pre == y@pre)
*/
while (x <= 100) {
    y = 100 - x;
    x = x + 1;
}

    
    /*@ (y >= 0) && (y < 100) */


}