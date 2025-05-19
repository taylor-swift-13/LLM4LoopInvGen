

void foo(int n) 
/*@
Require  n > 0
Ensure emp
*/{
 
  int i = 0;
  int k = 0;
  
  while( i < n ) {
	  i++;
	  k++;
  }

  int j = 0;
 
  while( j < n ) {
    /*@ k > 0*/
    j++;
    k--;
  }
}