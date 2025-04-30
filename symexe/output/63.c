
void foo(int y) {
    int x = 1;
    
    /*@Inv
      ((x == 1) && (y == y@pre)) || (y >= 0 && y <= 10)
    */
    while (x <= 10) {
        y = 10 - x;
        x = x + 1;
    }
    
    /*@ assert (y >= 0); */
}
