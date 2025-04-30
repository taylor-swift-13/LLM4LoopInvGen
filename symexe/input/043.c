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
   
  

  while (unknown()){
    if (x > 0)   
      y = y + x;
  }
   
  /*@  y >= t*/
 
}

