
void foo(int x, int y)
/*@  Require x >= 0 && x <= 10 && y <= 10 && y >= 0
     Ensure emp
*/ {
  
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv
    (x >= 0) && (x <= 10 + 10 * (x / 10)) && (y >= 0) && (y <= 10 + 10 * (y / 10))
    && (x == x@pre + 10 * (1 + (x - x@pre)/10)) && (y == y@pre + 10 * (1 + (y - y@pre)/10))
*/
while (1) {
    x = x + 10;
    y = y + 10;

    if (x == 20) {
        /*@ (y != 0) */
    }
}


  

}
 