void foo()
/*@  Require emp
     Ensure emp
*/ {
    int x = 1;
    int y = 10;
    
    
    while (x <= 10) {
        y = 10 - x;
        x = x +1;
    }

    /*@ (y >= 0) && (y < 10) */

}