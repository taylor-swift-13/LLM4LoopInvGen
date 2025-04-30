int unknown()
/*@ Require emp 
   Ensure __return <= INT_MAX && __return > INT_MIN
*/;





void foo()  
/*@ Require emp 
   Ensure emp
*/ 
    {
  int x = 0;
  int y = 0;
  int n = 0;
 
  while(unknown()) {
      x++;
      y++;
  }
 
  while(x!=n) {
      x--;
      y--;
  }
  /*@  y == n */
}
