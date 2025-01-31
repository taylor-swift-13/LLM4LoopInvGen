/*@ requires n >= 0; */
void foo(int n) {

  int x = n;
  int y = 0;

  
/*@
  loop invariant (\at(n, Pre) >= 0) ==> (y == \at(n, Pre) - x);
  loop invariant (\at(n, Pre) >= 0) ==> (x == \at(n, Pre) - y);
  loop invariant n == \at(n, Pre);
*/
while (x > 0) {

  y  = y + 1;
  x  = x - 1;

}

 /*@ assert y == n ;*/
}