void foo(int y,int z) {

    int x = 0;
    
    
    
    /*@
      loop invariant (0 <= x <= 5);
      loop invariant (0 < 5) ==> ( (y == \at(y, Pre)) || (y == z) );
      loop invariant z == \at(z, Pre);
    */
    while(x < 5) {
       x += 1;
       if( z <= y) {
          y = z;
       }
    }

   
   /*@ assert z >= y; */
}