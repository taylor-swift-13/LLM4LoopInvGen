
void foo(int n) {
    int x = 0;

    /*@Inv
      (n >= 0) => (x <= n) &&
      (n >= 0) => (x >= 0)
    */
    while (x < n) {
        x = (x + 1);
    }
    
    /*@ assert (n >= 0) ==> (x == n); */
}
