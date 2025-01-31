
void foo(int n)
/*@  Require emp
     Ensure emp
*/ {

  int x = n;
  int y = 0;
  
  
  while (x > 0) {
    
    y  = y + 1;
    x  = x - 1;

  }

  /*@  n == x + y */

}