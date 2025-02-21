void foo(int x)
/*@  Require emp
     Ensure emp
*/ {
  int i =0;
  int j =0;
  int y =1;
  
  
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv
    y == 1 
    && x == x@pre 
    && i >= 0 
    && j == i 
    && i <= x + 1
*/ 
while (i <= x) {
    
    i  = i + 1;
    j  = j + y;

}



  if(y == 1){
    /*@  (i == j)  */
  }

}