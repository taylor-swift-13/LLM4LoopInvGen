
void foo(int n) 
/*@
Require  n <= INT_MAX
Ensure emp
*/{
  int i,k;
  k = n;
  i = 0;

 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((n@pre <= INT_MAX) => ((0 < n@pre) => (((k == n@pre)&&(i == 0)&&(n == n@pre)) || (0 <= i && i <= n+1 && (i % 2 == 0)))) ) &&
((n@pre <= INT_MAX) => ((0 < n@pre) => (((k == n@pre)&&(i == 0)&&(n == n@pre)) || (k == n - i/2))) ) &&
((n@pre <= INT_MAX) => ((!(0 < n@pre)) => ((k == n@pre)&&(i == 0)&&(n == n@pre)))) &&
((n@pre <= INT_MAX) => (n == n@pre))
    */
                while( i < n ) {
    k--;
    i = i + 2;
  }

  int j = 0;
 
  
 
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv
    (k == n - i/2 - j) &&
(j < n/2 => k >= 0)
    */
                while( j < n/2 ) {
    /*@ Inv
    (assert k>0)
    */
    k--;
    j++;
  }

}