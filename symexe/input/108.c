
void foo(int m,int j,int a,int c)  
/*@ Require a <= m
   Ensure emp
*/ 
    {

    int k = 0;
    
    
    while ( k < c) {

        if(m < a) {
            m = a;
        }
        
        k = k + 1;
    }

  /*@  a <= m */

}