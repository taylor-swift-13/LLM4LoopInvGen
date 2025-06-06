


void foo(int n) 
/*@
Require  0 <= n && n < 1000
Ensure emp
*/{

    int i=0;
    int sn=0;
    
    

    for (i = 1; i <= n; i++) {
        sn = sn + (2);
    }
    
    /*@  sn == n * (2) || sn == 0*/
    

}
