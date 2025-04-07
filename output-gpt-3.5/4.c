void foo(int y,int z)
{
    int x = 0;   

    
    

/*@
  loop invariant  ((x == 0)&&(z == \at(z, Pre))&&(y == \at(y, Pre))) || (y <= z);
  loop invariant  ((x >= 0) && (x <= 500)); // This invariant correctly represents the bounds of x.
  loop invariant z == \at(z, Pre);
*/
while(x < 500) {
   x += 1;
   if( z <= y) {
      y = z;
   }
}



   
    /*@ assert z >= y; */
}