void foo(int y,int z)
/*@  Require emp
     Ensure emp
*/
{
    int x = 0;   

    
    while(x < 500) {
       x += 1;
       if( z <= y) {
          y = z;
       }
    }

   
    /*@  z >= y */
}