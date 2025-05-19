int unknown()
/*@ Require emp 
   Ensure __return <= INT_MAX && __return > INT_MIN
*/;

void foo(int x, int y)
 
/*@ Require x!=y
   Ensure emp
*/ 
    {
  int i=0;
  int t=y;
   
  

 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((x@pre != y@pre) => (((t == y@pre)&&(i == 0)&&(y == y@pre)&&(x == x@pre)) || (y >= y@pre))) &&
((x@pre != y@pre) => (t == y@pre)) &&
((x@pre != y@pre) => (i == 0)) &&
((x@pre != y@pre) => (x == x@pre))
    */
  while (unknown()){
    if (x > 0)   
      y = y + x;
  }
   
  /*@  y >= t*/
 
}

