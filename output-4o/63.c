void foo(int y) {
    int x = 1;
    
    
    
    
/*@  loop invariant  ((x == 1)&&(y == \at(y, Pre))) || ((1 <= x) && (x <= 11)) ;
*/
while (x <= 10) {
    y = 10 - x;
    x = x + 1;
}


    /*@ assert (y >= 0); */

}