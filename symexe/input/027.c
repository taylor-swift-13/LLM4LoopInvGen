
void foo(int l,int n)  
/*@ Require l>0
   Ensure emp
*/ 
    {
  int i, k;
 

  k =1;
  for (k =1; k < n; k++) {
    i =l;
    for (i=l; i < n; i++) {

    }

    /*@ (forall (i: Z), (l <= i && i < n) => (1 <= k)) */
  }

}