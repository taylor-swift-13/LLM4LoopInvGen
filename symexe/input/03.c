
void foo(int n, int l)  
/*@ Require l > 0 && n >l
   Ensure emp
*/ 
    {
  int i,k;
 
  k=1;
  for (k=1; k<n; k++){
  	i=l;
    for (i=l; i<n; i++) {
    }

    }


    /*@ (forall (i: Z), (l <= i && i < n) => (1 <= i)) */
    

}
