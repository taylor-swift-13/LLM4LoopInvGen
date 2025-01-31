
/*@ requires a <= m;
    requires j < 1;
*/
void foo(int m,int j,int a) {

    int k = 0;
    
    
    
    /*@
      loop invariant ( 0 < 1) ==> ( k >= 0 && k <= 1 );
      loop invariant ( 0 < 1) ==> ( (m == \at(m, Pre)) || (m == a) );
      loop invariant ( 0 < 1) ==> ( k == 0 || k == 1 );
      loop invariant ( 0 < 1) ==> ( (m == \at(m, Pre)) || (m == a) );
      loop invariant a == \at(a, Pre);
      loop invariant j == \at(j, Pre);
    */
    while ( k < 1) {

        if(m < a) {
            m = a;
        }
        
        k = k + 1;
    }


  /*@ assert a <= m; */

}