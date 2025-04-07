void foo(int x) {
    int i =0;
    int j =0;
    int y =2;
    
    
    
/*@
  loop invariant (0 <= \at(x, Pre)) ==> (i >= 0 && j == 2 * i && y == 2 && x == \at(x, Pre));
  loop invariant (0 <= \at(x, Pre)) ==> (i <= \at(x, Pre) + 1);
  loop invariant (!(0 <= \at(x, Pre))) ==> ((y == 2)&&(j == 0)&&(i == 0)&&(x == \at(x, Pre)));
  loop invariant y == 2;
  loop invariant x == \at(x, Pre);
*/
while (i <= x) {
    i  = i + 1;
    j  = j + y;
}

  
  /*@ assert (i != j) ==> (y != 1) ;*/
  
  }