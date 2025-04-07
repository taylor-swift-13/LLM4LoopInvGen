int unknown();
void foo(int n, int v1,int v2,int v3)  
/*@ Require n >0
   Ensure emp
*/ 
    {

    int c = 0;

    while (unknown()) {
        {
          if (unknown()) {
            if ( c != n )
            {
            c  = c + 1;
            }
          } else {
            if (c == n) 
            {
            c  = 1;
            }
          }
    
        }
    
    }
   
           
         /*@  (c != n) => (c >= 0) */
    

}