
void foo(int y,int z) {

    int x = 0;
    
    /*@
      Inv
      ((x == 0) && (z == z@pre) && (y == y@pre)) || (y <= y@pre && y >= 0) &&
      ((x == 0) && (z == z@pre) && (y == y@pre)) || (x == 0) &&
      z == z@pre;
    */
    while(x < 5) {
       x += 1;
       if( z <= y) {
          y = z;
       }
    }
            
    /*@ assert z >= y; */
}
