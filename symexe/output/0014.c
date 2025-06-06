


void foo(int n) 
/*@
Require  0 <= n && n < 1000
Ensure emp
*/{

    int i=0;
    int sn=0;
    
    

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 <= n@pre && n@pre < 1000) => ((0 <= n@pre) => (((sn == 0)&&(i == 0)&&(n == n@pre)) || (1 <= i && i <= n+1))) ) &&
((0 <= n@pre && n@pre < 1000) => ((!(0 <= n@pre)) => ((sn == 0)&&(i == 0)&&(n == n@pre)))) &&
((0 <= n@pre && n@pre < 1000) => (n == n@pre))
    */
                for (i = 1; i <= n; i++) {
        sn = sn + (2);
    }
    
    /*@  sn == n * (2) || sn == 0*/
    

}
