
void foo(int n)
/*@  Require n >= 0
     Ensure emp
*/ {
  
  int i = 0;
  int x = 0;
  int y = 0;
  

  while (i < n) {
    
    i  = i + 1;
      if ( i % 2 == 0) {
        
        x  = x + 1;
        y  = y + 2;
        
      } else {
        
        x  = x + 2;
        y  = y + 1;
        
      }


  }

  /*@ (3 * n) == (x + y) */

}