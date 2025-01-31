void foo(int n, int v1,int v2,int v3) {

  int x = n;
  
  
  
    /*@
      loop invariant (\at(n, Pre) > 1) ==> (x == (\at(n, Pre) - (\at(n, Pre) - x)));
      loop invariant v3 == \at(v3, Pre);
      loop invariant v2 == \at(v2, Pre);
      loop invariant v1 == \at(v1, Pre);
      loop invariant n == \at(n, Pre);
    */
    while (x > 1) {
    
     x  = x - 1;

  }


 /*@ assert (n >= 0) ==> (x == 1); */
}