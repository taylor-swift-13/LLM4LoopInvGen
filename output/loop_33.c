
/*@ requires x >= y  && y >= 0; */
void foo(int x, int y) {

  int i = 0;
  

  
  
  /*@
    loop invariant i >= 0 && i <= y;
    loop invariant y == \at(y, Pre);
    loop invariant x == \at(x, Pre);
  */
  while (1) {
    if ( i < y )
    {
      i  = (i + 1);
      /*@ assert (i >= 0 && i <= y); */
    }
  }


 
 
}