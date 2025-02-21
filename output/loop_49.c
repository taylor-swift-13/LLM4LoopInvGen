
void foo(int m,int j,int a)
/*@  Require a <= m && j < 1
     Ensure emp
*/ {

    int k = 0;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@Inv   
        a == a@pre 
        && j == j@pre 
        && k >= 0 
        && k <= 1 
        && m >= a@pre 
        && m == m@pre || m == a@pre
*/ 
while ( k < 1) {

        if(m < a) {
            m = a;
        }
        
        k = k + 1;
    }


  /*@  a <= m */

}