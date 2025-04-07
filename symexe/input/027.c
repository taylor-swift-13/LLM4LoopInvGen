
void foo(int l)  
/*@ Require l>0
   Ensure emp
*/ 
    {
  int i, k, n;
 

 
  for (k = 1; k < n; k++) {
    for (i = l; i < n; i++) {

    }

    /*@ (forall (i: Z), (l <= i && i < n) => (1 <= k)) */
  }

}