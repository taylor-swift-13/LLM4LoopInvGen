
void foo(int y) {
    int x = 1;
    

    
    while (x <= 100) {
        y = 100 - x;
        x = x +1;
    }
    
    /*@ assert (y >= 0) && (y < 100); */


}