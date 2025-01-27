
void foo(int n,int v1,int v2,int v3) {
    int y;
    int x = 1;

    
    while (x <= n) {
        y = n - x;
        x = x + 1;
    }

    /*@ assert (n > 0) ==> (y >= 0 && y <= n); */


}