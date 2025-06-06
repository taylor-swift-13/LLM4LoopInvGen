

void foo(int m,int j,int a)  
/*@ Require a <= m && j < 1
   Ensure emp
*/ 
    {

    int k = 0;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (((k == 0)&&(a == a@pre)&&(j == j@pre)&&(m == m@pre)) || (k == 1 && m >= a)) &&
(((k == 0)&&(a == a@pre)&&(j == j@pre)&&(m == m@pre)) || (k == 1 && m >= a)) &&
(a == a@pre) &&
(j == j@pre)
    */
    
    while (k < 1) {
        if(m < a) {
            m = a;
        }
        
        k = k + 1;
    }

  /*@  a <= m */

}