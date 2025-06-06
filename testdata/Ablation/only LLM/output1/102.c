
void foo(int n) {
    int x = 0;

    /*@ loop invariant 0 <= x <= n;
        loop assigns x;
        loop variant n - x;
     */
    while (x < n) {
        x = x + 1;
    }
    /*@ assert (n >= 0) ==> (x == n); */
}
