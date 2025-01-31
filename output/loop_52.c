
/*@ requires a <= m;*/
void foo(int m,int j,int a,int c) {

    int k = 0;
    
    
    
    /*@
      loop invariant ( 0 < \at(c, Pre)) ==> ( 0 <= k && k <= c );
      loop invariant ( 0 < \at(c, Pre)) ==> ( (m >= a && m == \at(m, Pre)) || (m == a && \at(m, Pre) < a) );
      loop invariant ( 0 < \at(c, Pre)) ==> ( 0 <= k && k <= c );
      loop invariant ( 0 < \at(c, Pre)) ==> ( (m >= a && m == \at(m, Pre)) || (m == a && \at(m, Pre) < a) );
      loop invariant c == \at(c, Pre);
      loop invariant a == \at(a, Pre);
      loop invariant j == \at(j, Pre);
    */
    while ( k < c) {

        if(m < a) {
            m = a;
        }
        
        k = k + 1;
    }


  /*@ assert (c > 0 ) ==> (a <= m); */
}