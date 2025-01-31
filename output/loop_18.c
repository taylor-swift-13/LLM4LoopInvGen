void foo(int n) {

  int x = n;
  
  
  
        /*@
          loop invariant (\at(n, Pre) > 1) ==> (x == \at(n, Pre) - (\at(n, Pre) - x));
          loop invariant n == \at(n, Pre);
        */
        while (x > 1) {
    
     x  = x - 1;

  }


 /*@ assert (n >= 0) ==> (x == 1); */
}