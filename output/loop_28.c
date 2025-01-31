
void foo(int y) {
    int x = 1;

    
    
    
    /*@
      loop invariant (1 <= x <= 100);
      loop invariant (y == 100 - x);
    */
    while (x <= 100) {
        y = 100 - x;
        x = x + 1;
    }

    
    /*@ assert (y >= 0) && (y < 100); */


}