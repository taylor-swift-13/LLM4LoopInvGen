void foo()
/*@  Require emp
     Ensure emp
*/ {
  int x = 100;
  
  
  while (x > 0) {
    
    x  = x - 1;
    
  }

  /*@ x == 0 */
}