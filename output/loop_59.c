void foo(int x, int y) {

  int i = x;
  int j = y;
  
  
  
/*@
  loop invariant (\at(x, Pre) != 0) ==> (y == \at(y, Pre) - (\at(x, Pre) - x));
  loop invariant (\at(x, Pre) != 0) ==> (x == \at(x, Pre) - (\at(x, Pre) - x));
  loop invariant j == \at(y, Pre);
  loop invariant i == \at(x, Pre);
*/
while (x != 0) {

  x  = x - 1;
  y  = y - 1;

}


  /*@ assert (i == j) ==> (y == 0); */

}