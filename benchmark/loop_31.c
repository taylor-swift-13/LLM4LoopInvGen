
/*@ requires 0 <= y && y <= 127; */
void foo(int y) {
  int c = 0;
  int z = 36 * y;
  



  while (1) {
    if ( c < 36 )
    {
    z  = z + 1;
    c  = c + 1;

    /*@ assert  z >= 0 && z < 4608; */
    }

  }



}