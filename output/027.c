
    /*@
    Inv
    ((l@pre > 0) => ((1 < n@pre) => (((k == 1)&&(n == n@pre)&&(l == l@pre)) || (k < n)))) &&
    ((l@pre > 0) => ((!(1 < n@pre)) => ((k == 1)&&(n == n@pre)&&(l == l@pre)))) &&
    ((l@pre > 0) => (n == n@pre)) &&
    ((l@pre > 0) => (l == l@pre))
    */
                for (k = 1; k < n; k++) {
    i = l;
    
    /*@ Inv
    (1 <= k) && (l <= i && i < n)
    */
    for (i = l; i < n; i++) {
    }
    
    /*@ assert \forall integer j; (l <= j && j < n) => (1 <= k);
    */
  }
    