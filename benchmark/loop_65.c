/*@ requires n >= 0; */
void foo(int n) {

  int x = 0;
  int x0;

  
  while (x < n) {
    {
     x  = x + 1;
    }

  }
  /*@ assert x == n; */

}