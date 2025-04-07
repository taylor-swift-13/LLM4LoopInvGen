void foo(int y,int z1,int z2,int z3)  
/*@ Require emp 
   Ensure emp
*/ 
    {

    int x = 1;
    
    
    while (x < y) {
  
       x  = x + x;
       
    }
  
    /*@  x >= 1*/
  
  }