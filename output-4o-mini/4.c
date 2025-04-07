void foo(int y,int z)
{
    int x = 0;   

    
    

/*@
  loop invariant  ((x == 0) && (z == \at(z, Pre)) && (y == \at(y, Pre))) || (y <= z) ;
  loop invariant  (x <= 500) ; // Added invariant to ensure x does not exceed 500
*/
while(x < 500) {
   x += 1;
   if( z <= y) {
      y = z;
   }
}



   
    /*@ assert z >= y; */
}