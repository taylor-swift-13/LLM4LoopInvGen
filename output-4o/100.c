
void foo(int n) {

    int x = n;
    int y = 0;
    
    
    
/*@
  loop invariant y + x == n;
  loop invariant n == \at(n, Pre);
  loop invariant x >= 0; // Ensures x never becomes negative
*/
while (x > 0) {
  y = y + 1;
  x = x - 1;
}

/*@ assert y == n ; */

  
    /*@ assert y == n ; */
  
  }