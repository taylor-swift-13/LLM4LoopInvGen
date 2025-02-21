
void foo()
/*@  Require emp
     Ensure emp
*/ {
    int x = 1;
    int y;
    

    
    while (x <= 100) {
        y = 100 - x;
        x = x +1;
    }
    
    /*@ (y >= 0) && (y < 100) */


}