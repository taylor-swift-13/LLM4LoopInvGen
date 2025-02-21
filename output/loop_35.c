
void foo(int y)
/*@  Require emp
     Ensure emp
*/ {

  int x = -5000;

  
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv
    x == -5000 + (y@pre * (y - y@pre)) 
    && x <= -5000 + ((y@pre * (y - y@pre)) + y) / 2
    && x < 0
    && y > y@pre
*/
while (x < 0) {
    x = x + y;
    y = y + 1;
}

  /*@  y > 0 */

}
