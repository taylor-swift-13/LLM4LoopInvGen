void foo(int n)
{
    int x = 1;
    int m = 1;
    
    
    
/*@  loop invariant (1 < \at(n, Pre)) ==> (((m == 1) && (x == 1) && (n == \at(n, Pre))) || (m >= 1 && m < n));
  loop invariant !(1 < \at(n, Pre)) ==> ((m == 1) && (x == 1) && (n == \at(n, Pre)));
  loop invariant n == \at(n, Pre);
  loop invariant x >= 1; // x is always at least 1 at the start of the loop
*/
while (x < n) {
    if (unknown()) {
        m = x; // m can be updated to the current value of x
    }
    
    x = x + 1; // x is incremented
}

 
    /*@ assert (n > 1) ==> (m >= 1); */

}