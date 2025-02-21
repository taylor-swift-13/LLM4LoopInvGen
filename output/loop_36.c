
void foo(int y)
/*@  Require emp
     Ensure emp
*/ {

  int x = -50;

  
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv
    x == (-50 + (y@pre * (y - y@pre)) + (((y - y@pre) * ((y - y@pre) - 1)) / 2))
    && y >= y@pre
    && x <= ((-50) + ((y - y@pre) * (y@pre + ((y - y@pre) - 1) / 2)))
*/
while (x < 0) {
    x = x + y;
    y = y + 1;
}

  /*@ y > 0 */

}
