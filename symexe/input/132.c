int unknown();
void foo(int j,int c,int t)  
/*@ Require emp 
   Ensure emp
*/ 
    {

    int i = 0;



while(unknown()) {
        if(c > 48) {
            if (c < 57) {
                j = i + i;
                t = c - 48;
                i = j + t;
            }
        }
    } 

    /*@  i >= 0 */


}