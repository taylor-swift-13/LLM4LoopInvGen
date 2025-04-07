int unknown();

void foo(int x, int y)  
/*@ Require x >= 0 && x <= 10 && y <= 10 && y >= 0  
   Ensure emp
*/ 
    {
  
  
    while (unknown()) {
      
        x = x + 10;
        y = y + 10;
        
      
    }

    /*@  (y == 0) =>  (x != 20) */

  }