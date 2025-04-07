
void foo(int n, int l)  
/*@ Require l > 0 && n >l
   Ensure emp
*/ 
    {
  int i,k;

  
  for (k=1; k<n; k++){
  	
    for (i=l; i<n; i++) {
    }

    }


    /*@ (forall (i: Z), (l <= i && i < n) => (1 <= i)) */
    

}
