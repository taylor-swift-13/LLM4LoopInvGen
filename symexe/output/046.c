
int unknown()
/*@ Require emp 
   Ensure __return <= INT_MAX && __return > INT_MIN
*/;


void foo()  
/*@ Require emp 
   Ensure emp
*/ 
    {

  int w = 1;
  int z = 0;
  int x = 0;
  int y = 0;


 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (((y == 0)&&(x == 0)&&(z == 0)&&(w == 1)) || (w % 2 == 0) ) &&
(((y == 0)&&(x == 0)&&(z == 0)&&(w == 1)) || (x <= 1) )
    */
    
                while (unknown()) {
    if (w % 2 == 1) {
      x++;
      w++;
    }
    if (z % 2 == 0) {
      y++;
      z++;
    }
  }

  /*@  x <= 1 */

}