
void foo(int n) 
/*@
Require  n <= INT_MAX
Ensure emp
*/{
  int i,k;
  k = n;
  i = 0;

  while( i < n ) {
    k--;
    i = i + 2;
  }

  int j = 0;
 
  
  while( j < n/2 ) {
    /*@  k>0 */
    k--;
    j++;
  }

}