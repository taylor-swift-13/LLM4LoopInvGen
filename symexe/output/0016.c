

void foo(int n) 
/*@
Require  n > 0
Ensure emp
*/{
 
  int i = 0;
  int k = 0;
  
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while( i < n ) {
	  i++;
	  k++;
  }

  int j = 0;
 
 
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv
    (0 <= j && j <= n) &&
(k + j == n) &&
((j < n) => (k > 0))
    */
                while( j < n ) {
    /*@ Inv
    (assert k > 0)
    */
    j++;
    k--;
  }
}