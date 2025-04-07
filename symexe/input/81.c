int unknown();

void foo(int x, int y,int z1,int z2,int z3)  
/*@ Require  x >= y  && y >= 0
   Ensure emp
*/ 
    {

    int i = 0;
    
  
    
    while (unknown()) {
      if ( i < y )
      {
      i  = i + 1;
      }
  
    }
  

       /*@  (i < y) => (i >= 0) */
    
  

}