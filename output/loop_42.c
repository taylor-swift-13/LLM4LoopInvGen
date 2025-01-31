void foo(int x) {
  int i =0;
  int j =0;
  int y =1;
  
  
  
        /*@
          loop invariant (0 <= \at(x, Pre)) ==> (j == i * y);
          loop invariant (0 <= \at(x, Pre)) ==> (0 <= i && i <= x + 1);
          loop invariant y == 1;
          loop invariant x == \at(x, Pre);
        */
        while (i <= x) {
    
    i  = i + 1;
    j  = j + y;

  }


/*@ assert (y == 1) ==> (i == j) ;*/

}