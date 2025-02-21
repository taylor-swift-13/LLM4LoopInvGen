
void foo(int y)
/*@  Require emp
     Ensure emp
*/ {

  int x = 1;
  
  
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv   
    y == y@pre 
    && x >= 1 
    && x <= y@pre 
    && exists n, n >= 0 && x == 1 * (2^n) 
*/
while (x < y) {
    x = x + x;
}


  /*@  x >= 1 */

}
