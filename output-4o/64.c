void foo(int y) {
    int x = 1;
    
    
    
/*@
  loop invariant  ((x == 1)&&(y == \at(y, Pre))) || (y == 10 - x + 1) ;
*/
while (x <= 10) {
    y = 10 - x;
    x = x + 1;
}


    /*@ assert (y < 10); */

}