void foo() {

    int x = 0;
    int y = 0;

    
    
/*@
  loop invariant  ((y == 0) && (x == 0)) || (y == 0);
  loop invariant x == 0;
*/
while (y >= 0) {
    y = y + x; // Here, since x == 0, y will always remain equal to its current value
}

    /*@ assert y >= 0;*/

}