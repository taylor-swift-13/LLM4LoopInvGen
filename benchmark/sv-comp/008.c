
/*@
requires a < 1000000;
requires 0 <= b && b <= 1000000;
*/
void foo(int a, int b) {

    int res, cnt;
    res = a;
    cnt = b;
    

    while (cnt > 0) {
    	cnt = cnt - 1;
        res = res + 1;
    }

    /*@ assert res == a + b;*/
    

}
