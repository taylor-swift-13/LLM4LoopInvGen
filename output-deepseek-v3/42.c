int unknown();
/*@ requires n > 0; */
void foo(int n)  {

    int c = 0;

    
/*@  loop invariant (\at(n, Pre) > 0) ==> (n == \at(n, Pre));
  loop invariant (\at(n, Pre) > 0) ==> (c == 1 ==> 0 <= c <= n + 1);
*/
while (unknown()) {
    {
        if (unknown()) {
            if (c > n) {
                c = c + 1;
            }
        } else {
            if (c == n) {
                c = 1;
            }
        }
    }
}

           
    /*@ assert ((c < 0)&& (c > n)) ==> (c == n); */
    

}