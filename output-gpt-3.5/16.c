void foo(int n)
{
    int x = 0;
    int m = 0;

    
    
/*@  loop invariant (!(0 < \at(n, Pre))) ==> ((m == 0)&&(x == 0)&&(n == \at(n, Pre)));
  loop invariant n == \at(n, Pre);
*/
while (x < n) {
    if (unknown()) {
        m = x; // m takes the value of x if the condition is true
    }
    x = x + 1; // x is incremented in each iteration
}


    /*@ assert (n > 0) ==> (m >= 0); */

}