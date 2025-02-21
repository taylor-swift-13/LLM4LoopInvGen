
void foo(int m,int j,int a)
/*@  Require emp
     Ensure emp
*/ {

    int k = 0;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv 
    a == a@pre 
    && j == j@pre 
    && m >= a 
    && m == ((m@pre > a) ? m@pre : a) 
    && k >= 0 
    && k <= 1 
*/
while (k < 1) {

    if (m < a) {
        m = a;
    }
    
    k = k + 1;
}


  /*@  a <= m */

}
