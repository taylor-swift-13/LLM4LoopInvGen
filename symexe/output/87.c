int unknown();
int main(int y)  
/*@ Require emp 
   Ensure emp
*/ 
    {

    int lock = 1;
    int x = y;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((y@pre != y@pre) => (((x == y@pre)&&(lock == 1)&&(y == y@pre)) || (y == y@pre))) &&
((y@pre != y@pre) => (((x == y@pre)&&(lock == 1)&&(y == y@pre)) || (lock == 1))) &&
((y@pre != y@pre) => (((x == y@pre)&&(lock == 1)&&(y == y@pre)) || (x == y@pre))) &&
((!(y@pre != y@pre)) => ((x == y@pre)&&(lock == 1)&&(y == y@pre)))
    */
    
    while (x != y) {
        if (1) {
            lock = 1;
            x = y;
        } else {
            lock = 0;
            x = y;
            y = y + 1;
        }
    }
    /*@  lock == 1*/
  }