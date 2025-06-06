
void foo(int m,int j,int a,int c)  
/*@ Require a <= m
   Ensure emp
*/ 
    {

    int k = 0;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < c@pre) => (((k == 0)&&(c == c@pre)&&(a == a@pre)&&(j == j@pre)&&(m == m@pre)) || (a <= m))) &&
((0 < c@pre) => (((k == 0)&&(c == c@pre)&&(a == a@pre)&&(j == j@pre)&&(m == m@pre)) || (k <= c))) &&
((!(0 < c@pre)) => ((k == 0)&&(c == c@pre)&&(a == a@pre)&&(j == j@pre)&&(m == m@pre))) &&
(c == c@pre) &&
(a == a@pre) &&
(j == j@pre)
    */
    
                while ( k < c) {

        if(m < a) {
            m = a;
        }
        
        k = k + 1;
    }

  /*@  a <= m */

}