void foo(int y,int z1,int z2,int z3)
/*@  Require emp
     Ensure emp
*/ {

  int x = -50;

  
  while (x < 0) {
    
    x  = x + y;
    y  = y + 1;
    

  }
  /*@  y > 0 */

}