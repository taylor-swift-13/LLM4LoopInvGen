
void foo(int n)
{
    int x = 1;
    int m = 1;
    
    /*@Inv
      (1 < n@pre) ==> (1 <= x && x <= n) &&
      !(1 < n@pre) ==> (m == 1 && x == 1) &&
      n == n@pre &&
      (1 < n) ==> (m < n)
    */
    while (x < n) {
        if (1) {
            m = x;
        }
        x = x + 1;
    }
    
    /*@ assert (n > 1) ==> (m < n); */
}
