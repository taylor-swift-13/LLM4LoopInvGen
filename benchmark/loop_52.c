
/*@ requires a <= m;*/
void foo(int m,int j,int a,int c) {

    int k = 0;
    
    
    while ( k < c) {

        if(m < a) {
            m = a;
        }
        
        k = k + 1;
    }

  /*@ assert (c > 0 ) ==> (a <= m); */
}