
void foo(int n) {
    int i = 0;

    /*@
    loop invariant 0 <= i <= n;
    loop invariant \at(n, Pre) == n;
    loop invariant \at(i, LoopEntry) <= i;
    */
    while (i < n) {
        i = i + 1;
    }
    /*@ assert n > 0 ==> i == n; */
}
