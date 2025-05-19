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
 
 
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while(x != 0) {
	  x--;
	  y--;
  }

  /*@  (i == j) => (y == 0)*/
}
