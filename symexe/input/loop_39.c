void foo()
/*@  Require emp
     Ensure emp
*/ {

    int x = 0;
    int y = 0;

    
    while(y >= 0) {
        y = y + x;
    }
    /*@ y >= 0 */

}