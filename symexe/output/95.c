void foo(int x)  
/*@ Require emp 
   Ensure emp
*/ 
    {
    int i =0;
    int j =0;
    int y =1;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 <= x@pre) => (((y == 1)&&(j == 0)&&(i == 0)&&(x == x@pre)) || (j == i))) &&
((0 <= x@pre) => (((y == 1)&&(j == 0)&&(i == 0)&&(x == x@pre)) || (j == i))) &&
((!(0 <= x@pre)) => ((y == 1)&&(j == 0)&&(i == 0)&&(x == x@pre))) &&
(y == 1) &&
(x == x@pre)
    */
    
    while (i <= x) {
      i = i + 1;
      j = j + y;
    }
  
  /*@  (y == 1) => (i == j) */
  
  }