void foo(int size,int y,int z)
{
    int x = 0;
    
   
    
    /*@
      loop invariant (0 < \at(size, Pre)) ==> (0 <= x <= \at(size, Pre));
      loop invariant (0 < \at(size, Pre)) ==> ( (y == \at(y, Pre)) || (y == z));
      loop invariant z == \at(z, Pre);
      loop invariant size == \at(size, Pre);
    */
    while(x < size) {
       x += 1;
       if( z <= y) {
          y = z;
       }
    }


   /*@ assert (size > 0) ==> (z >= y);  */
}