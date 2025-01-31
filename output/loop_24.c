/*@ requires n > 0; */
void foo(int n) {

    int c = 0;

    
    
    /*@
      loop invariant (1) ==> ( (c >= 0) && (c <= n) );
      loop invariant (1) ==> ( (c == 0) || ((c > 0) && (c <= n)) );
      loop invariant n == \at(n, Pre);
    */
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