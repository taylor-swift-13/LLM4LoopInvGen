
void foo(int n,int y,int v1,int v2,int v3) {
    
    int x = 1;

    /*@Inv
      v3 == v3@pre &&
      v2 == v2@pre &&
      v1 == v1@pre &&
      n == n@pre
    */
    while (x <= n) {
        y = n - x;
        x = x + 1;
    }

    /*@ assert (n > 0) ==> (y >= 0); */
}
