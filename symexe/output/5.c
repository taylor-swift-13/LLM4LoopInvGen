void foo(int size,int y,int z)
 
/*@ Require emp 
   Ensure emp
*/ 
    {
    int x = 0;
    
   
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < size@pre) => (((x == 0)&&(z == z@pre)&&(y == y@pre)&&(size == size@pre)) || (z >= y))) &&
((0 < size@pre) => (((x == 0)&&(z == z@pre)&&(y == y@pre)&&(size == size@pre)) || (0 <= x && x <= size))) &&
((!(0 < size@pre)) => ((x == 0)&&(z == z@pre)&&(y == y@pre)&&(size == size@pre))) &&
(z == z@pre) &&
(size == size@pre)
    */
    
    while(x < size) {
        x += 1;
        if( z <= y) {
            y = z;
        }
    }

   /*@  (size > 0) => (z >= y)  */
}