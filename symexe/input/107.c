
void foo(int m,int j,int a)  
/*@ Require emp 
   Ensure emp
*/ 
    {

    int k = 0;
    
    
    while ( k < 1) {

        if(m < a) {
            m = a;
        }
        
        k = k + 1;
    }

  /*@  a <= m */

}