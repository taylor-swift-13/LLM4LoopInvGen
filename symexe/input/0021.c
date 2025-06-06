
int unknown1();

void foo(int k, int n)
/*@
Require n < INT_MAX && k == n
Ensure emp
*/{
    int i,j;

    i =0  ;
   
    for (i = 0; i < n; i++) {
        
        j = 2 * i;
        for (j= 2 * i; j < n; j++) {

            if(unknown1()) {
                k = j;
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