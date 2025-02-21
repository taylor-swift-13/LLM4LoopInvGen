void foo(int v1, int v2 ,int v3,int size, int y, int z)
/*@  Require emp
     Ensure emp
*/
{
    
    int x = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv   
    z == z@pre 
    && size == size@pre 
    && v3 == v3@pre 
    && v2 == v2@pre 
    && v1 == v1@pre 
    && x >= 0 
    && x <= size 
    && (x == 0 => y == y@pre) 
    && (x > 0 => y == (z <= y@pre ? z : y@pre))
*/ 
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