
void foo(int n,int y) {
    
    int x = 1;

    
    
    /*@
      loop invariant (1 <= \at(n, Pre)) ==> (1 <= x && x <= \at(n, Pre) + 1);
      loop invariant (1 <= \at(n, Pre)) ==> (y == \at(n, Pre) - x || y == \at(y, Pre));
      loop invariant n == \at(n, Pre);
    */
    while (x <= n) {
        y = n - x;
        x = x + 1;
    }


    /*@ assert (n > 0) ==> (y >= 0 && y <= n); */


}