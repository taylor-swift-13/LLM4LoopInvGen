
void foo(int n)
/*@  Require n > 0
     Ensure emp
*/ {

    int c = 0;

    
    while (1){
        if(c == n) {
            c = 1;
        }
        else {
            c = c + 1;
        }

        /*@ (c >= 0) && (c <= n) */
    }

  

}