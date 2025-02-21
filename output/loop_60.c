void foo(int x, int y,int z1,int z2,int z3)
/*@  Require emp
     Ensure emp
*/ {

  int i = x;
  int j = y;
  
  
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv   
     j == y@pre  
  && i == x@pre  
  && z3 == z3@pre  
  && z2 == z2@pre  
  && z1 == z1@pre  
  && x >= 0  
  && y == y@pre - (x@pre - x)  
  && x <= x@pre 
*/ 
while (x != 0) {

    x  = x - 1;
    y  = y - 1;

}


  if(i == j){
  /*@  (y == 0) */
  }

}