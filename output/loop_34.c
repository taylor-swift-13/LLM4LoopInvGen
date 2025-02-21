
void foo(int x, int y,int z1,int z2,int z3)
/*@  Require x >= y  && y >= 0
     Ensure emp
*/ {

  int i = 0;
  

  
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv   
    z3 == z3@pre && z2 == z2@pre && z1 == z1@pre && y == y@pre && x == x@pre 
    && i >= 0 && i <= y && x >= y
*/ 
while (1) {
    if (i < y) {
        i = (i + 1);
        /*@ (i >= 0 && i < x) */
    }
}



 
}