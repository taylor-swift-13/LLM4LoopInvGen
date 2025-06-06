
int unknown1();

void foo(int k, int n)
/*@
Require n < INT_MAX && k == n
Ensure emp
*/{
    int i,j;

    i =0  ;
   
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (i = 0; i < n; i++) {
        
        j = 2 * i;
       
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv emp */ /*1*/ 
 for (j= 2 * i; j < n; j++) {

            if(unknown1()) {
                k = j;
               
  /*@ Print user assertion at number LoopEntry_2*/ 
/*@ Inv emp */ /*2*/ 
 for (k = j; k < n; k++) {
                    /*@ k >= 2*i*/
                }
            }
            else {
                /*@  k>=n && k <= n*/
            }
        }
    }

}