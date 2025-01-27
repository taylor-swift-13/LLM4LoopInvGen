/*@ requires n > 0; */
void foo(int n,int v1,int v2,int v3) {

    int c = 0;

    
    while (1){
        if(c == n) {
            c = 1;
        }
        else {
            c = c + 1;
        }
         /*@ assert (c >= 0) && (c <= n); */
    }

  

}