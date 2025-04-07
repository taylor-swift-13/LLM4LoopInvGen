
void foo(int n) {

    int x = n;
    int y = 0;
    
    
    
/*@
  loop invariant x + y == \at(n, Pre);
  loop invariant n == \at(n, Pre);
  loop invariant y >= 0;
  loop invariant x == 0 ==> y == \at(n, Pre);
  loop invariant x > 0 ==> y == \at(n, Pre) - x;
*/
while (x > 0) {
    y = y + 1;
    x = x - 1;
}

  
    /*@ assert y == n ; */
  
  }