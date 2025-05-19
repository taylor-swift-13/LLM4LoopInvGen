int unknown();
void foo(int x, int y,int z1,int z2,int z3)  
/*@ Require x >= 0 && x <= 10 && y <= 10 && y >= 0 
   Ensure emp
*/ 
    {
  
  
    while (unknown()) {
      
        x = x + 10;
        y = y + 10;
      
       
    }

   /*@  (x ==20) =>  (y != 0) */
   
}