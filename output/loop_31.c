
/*@ requires 0 <= y && y <= 127; */
void foo(int y) {
  int c = 0;
  int z = 36 * y;
  



  
/*@
  loop invariant z == 36 * \at(y, Pre) + c;
  loop invariant 0 <= c <= 36;
  loop invariant y == \at(y, Pre);
*/
while (1) {
  if ( c < 36 )
  {
    z  = z + 1;
    c  = c + 1;
    /*@ assert z >= 0 && z < 4608; */
  }
}




}