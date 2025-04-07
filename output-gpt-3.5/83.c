void foo(int y) {

    int x = -5000;
  
    
    
            /*@
          loop invariant  (x == -5000) || (x < \at(x, Pre)); // x is less than -5000 or equal to its initial value
          loop invariant  (y >= \at(y, Pre)); // y is non-decreasing from its initial value
            */
            while (x < 0) {
      
      x  = x + y;
      y  = y + 1;
      
  
    }

    /*@ assert y > 0; */
  
  }