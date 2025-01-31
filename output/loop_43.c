void foo(int x) {
  int i =0;
  int j =0;
  int y =2;
  
  
  
    /*@
      loop invariant (0 <= \at(x, Pre)) ==> (j == 2 * i);
      loop invariant (0 <= \at(x, Pre)) ==> (i <= x + 1);
      loop invariant y == 2;
      loop invariant x == \at(x, Pre);
    */
    while (i <= x) {
    
     i  = i + 1;
     j  = j + y;

  }


/*@ assert (y == 2) ==> ( 2 * i == j) ;*/
}