int unknown()
/*@ Require emp 
   Ensure __return <= INT_MAX && __return > INT_MIN
*/;


void foo(int i, int j)  
/*@ Require emp 
   Ensure emp
*/ 
    {
  
  int x = i;
  int y = j;
 
 
  while(x != 0) {
	  x--;
	  y--;
  }

  /*@  (i == j) => (y == 0)*/
}
