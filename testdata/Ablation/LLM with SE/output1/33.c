
void foo(int n,int v1,int v2,int v3) {

    int x = n;

    /* >>> LOOP INVARIANT FILLED <<< */
        
    /*@
      loop invariant (\at(n, Pre) > 0) ==> (((x == \at(n, Pre))&&(v3 == \at(v3, Pre))&&(v2 == \at(v2, Pre))&&(v1 == \at(v1, Pre))&&(n == \at(n, Pre))) || (0 <= x <= \at(n, Pre)));
      loop invariant (!(\at(n, Pre) > 0)) ==> ((x == \at(n, Pre))&&(v3 == \at(v3, Pre))&&(v2 == \at(v2, Pre))&&(v1 == \at(v1, Pre))&&(n == \at(n, Pre)));
      loop invariant v3 == \at(v3, Pre);
      loop invariant v2 == \at(v2, Pre);
      loop invariant v1 == \at(v1, Pre);
      loop invariant n == \at(n, Pre);
    */
    while (x > 0) {
      x = x - 1;
    }

    /*@ assert (x != 0) ==> (n < 0); */
}
