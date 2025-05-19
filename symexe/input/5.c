void foo(int size,int y,int z)
 
/*@ Require emp 
   Ensure emp
*/ 
    {
    int x = 0;
    
   
    while(x < size) {
       x += 1;
       if( z <= y) {
          y = z;
       }
    }

   /*@  (size > 0) => (z >= y)  */
}