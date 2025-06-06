

void foo(int n, int v) 
/*@
Require 0 <= n && n < 2 && 0 <= v
Ensure emp
*/{
  int c1 = 4000;
  int c2 = 2000;
  int c3 = 10000;
  
  int i, k, j;


  k = 0;
  i = 0;


  while( i < n ) {
    i++;
    if( v == 0 )
      k += c1;
    else if( v == 1 )
      k += c2;
    else
      k += c3;
  }

  j = 0;

  while( j < n ) {
    /*@ k > 0*/
    j++;
    k--;
  }

}