void foo(int v1, int v2 ,int v3,int size, int y, int z)
/*@  Require emp
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

   if(size > 0){
    /*@ (z >= y) */
    }
}