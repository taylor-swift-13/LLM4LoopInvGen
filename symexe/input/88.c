int unknown();
int main(int x)  
/*@ Require emp 
   Ensure emp
*/ 
    {

    int lock = 1;
    int y = x + 1;

    while (x != y) {
        if ( unknown()) {
          
          lock  = 1;
          x  = y;
          
        } else {
          
          lock  = 0;
          x  = y;
          y  = y + 1;
          
        }
 
    }
    /*@  lock == 1*/
  }