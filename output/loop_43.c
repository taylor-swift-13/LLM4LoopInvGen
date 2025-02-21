void foo(int x)
/*@  Require emp
     Ensure emp
*/ {
  int i =0;
  int j =0;
  int y =2;
  
  
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv 
    y == 2 
    && x == x@pre 
    && j == 2 * i 
    && 0 <= i 
    && i <= x + 1 
*/ 
while (i <= x) {
    i = i + 1;
    j = j + y;
}


 if(y == 2 ){
  /*@  ( 2 * i == j)  */
 }
 
}