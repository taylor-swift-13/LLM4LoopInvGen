
void foo(int n, int l)  
/*@ Require l > 0 && n >l
   Ensure emp
*/ 
    {
  int i,k;
 
  k=1;
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((l@pre > 0 && n@pre > l@pre) => ((!(1<n@pre)) => ((k == 1)&&(l == l@pre)&&(n == n@pre)))) &&
((l@pre > 0 && n@pre > l@pre) => (l == l@pre)) &&
((l@pre > 0 && n@pre > l@pre) => (n == n@pre))
    */
                for (k=1; k<n; k++){
  	i = l;
    
                
        /*@ Inv
    (1 <= i && i <= n
        loop assigns i)
    */
        for (i=l; i<n; i++) {
    }
                

    }


    /*@ (forall (i: Z), (l <= i && i < n) => (1 <= i)) */
    

}
