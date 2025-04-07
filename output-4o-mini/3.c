void foo(int y,int z) {

    int x = 0;
    
    
    
/*@
  loop invariant  (z == \at(z, Pre)) && (y <= \at(y, Pre)) || (y <= z);
  loop invariant  (x >= 0 && x <= 5);
  loop invariant  (y <= z) || (x < 5);
*/
while(x < 5) {
   x += 1;
   if( z <= y) {
      y = z;
   }
}

   
   /*@ assert z >= y; */
}