void foo(int x, int y) {

    int i = x;
    int j = y;
    
    
    
/*@
  loop invariant (\at(x, Pre) - \at(y, Pre)) == (x - y);
  loop invariant j == \at(y, Pre);
  loop invariant i == \at(x, Pre);
*/
while (x != 0) {

  x = x - 1;
  y = y - 1;

}

  
    /*@ assert (y != 0) ==> (i != j); */
  
  }