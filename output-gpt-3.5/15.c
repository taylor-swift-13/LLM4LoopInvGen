void foo(int n)
{
    int x = 0;
    int m = 0;

    
    
/*@
  loop invariant (0 < \at(n, Pre)) ==> ((m < n) && (x <= n)); // Ensure m is less than n and x does not exceed n
  loop invariant (0 < \at(n, Pre)) ==> (x <= \at(n, Pre)); // x should always be less than or equal to the initial n value
  loop invariant !(0 < \at(n, Pre)) ==> ((m == 0) && (x == 0) && (n == \at(n, Pre))); // When n is not positive, m and x are initialized
  loop invariant n == \at(n, Pre); // n must remain constant throughout the loop
*/
while (x < n) {

    if (unknown()) {
        m = x;
    }
    
    x = x + 1;
}


    /*@ assert (n > 0) ==> (m < n); */

}