void foo(int y,int z)
/*@  Require emp
     Ensure emp
*/ {

    int x = 0;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv   
    z == z@pre 
    && x >= 0 
    && x <= 5 
    && (x == 0 => y == y@pre) 
    && (x > 0 => y <= y@pre) 
    && (x > 0 => y == (z <= y@pre ? z@pre : y@pre))
*/ 
while(x < 5) {
    x += 1;
    if( z <= y) {
       y = z;
    }
}

   
   /*@  z >= y */
}