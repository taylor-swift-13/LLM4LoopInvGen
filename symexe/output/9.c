int unknown();

void foo(int x,int y)  
/*@ Require x >= 0 && x <= 2 && y <= 2 && y >= 0
   Ensure emp
*/ 
    {

  
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((x@pre >= 0 && x@pre <= 2 && y@pre <= 2 && y@pre >= 0) => (((y == y@pre)&&(x == x@pre)) || (x == x@pre + 2 * (y - y@pre) / 2)) ) &&
((x@pre >= 0 && x@pre <= 2 && y@pre <= 2 && y@pre >= 0) => (((y == y@pre)&&(x == x@pre)) || (y == y@pre + 2 * (x - x@pre) / 2)) )
    */
    
    while (unknown()) {
        x = x + 2;
        y = y + 2;
    }
    /*@  (x == 4) => (y != 0)  */

   
  
  }