void foo(int n) {

  int x = n;
  
  
  
        /*@
          loop invariant (\at(n, Pre) > 0) ==> (x >= 0 && x <= \at(n, Pre));
          loop invariant n == \at(n, Pre);
        */
        while (x > 0) {
    
     x  = x - 1;

  }


 /*@ assert (n >= 0) ==> (x == 0); */
}