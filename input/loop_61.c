void foo(int y)
/*@  Require emp
     Ensure emp
*/ {

  int x = 1;
  
  
  while (x < y) {

     x  = x + x;
     
  }

  /*@  x >= 1 */

}