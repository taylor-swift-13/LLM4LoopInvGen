void foo()
/*@  Require emp
     Ensure emp
*/ {
  int x = 10000;
  
  
  while (x > 0) {
    
    x  = x - 1;
    
  }

  /*@ x == 0 */
}