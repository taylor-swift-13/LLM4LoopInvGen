void foo() {
    int x = 1;
    int y = 10;
    
    
    
    /*@
      loop invariant (1 <= 10) ==> ( (y == 10 - x + 1) || (y == 10) );
      loop invariant (1 <= 10) ==> ( (x >= 1) && (x <= 11) );
    */
    while (x <= 10) {
        y = 10 - x;
        x = x + 1;
    }


    /*@ assert (y >= 0) && (y < 10); */

}