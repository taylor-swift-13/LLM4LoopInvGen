/*@ requires n >= 0; */
void foo(int n) {

  int x = 0;
  int x0;

  
  
  /*@
    loop invariant (0 <= x <= \at(n, Pre));
    loop invariant n == \at(n, Pre);
  */
  while (x < n) {
    {
      x  = x + 1;
    }
  }

  /*@ assert x == n; */

}