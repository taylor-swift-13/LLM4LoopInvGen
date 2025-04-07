int unknown();


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
