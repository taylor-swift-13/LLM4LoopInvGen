
int unknown1();

/*@ 
requires 0 <= n && n < 1000000;
*/
int foo(int n) {
    int i = 0; 
    int a = 0; 
    int b = 0; 
    
   
    while (i < n) {
        if (unknown1()) {
            a = a + 1;
            b = b + 2;
        } else {
            a = a + 2;
            b = b + 1;
        }
        i = i + 1;
    }

    /*@ assert a + b == 3 * n;*/
    
    return 0;
}
