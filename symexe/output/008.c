

void foo(int a, int b) 
/*@
Require a < 1000000 && 0 <= b && b <= 1000000
Ensure emp
*/{

    
    int res, cnt;
    res = a;
    cnt = b;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (cnt > 0) {
    	cnt = cnt - 1;
        res = res + 1;
    }

    /*@res == a + b*/
    

}
