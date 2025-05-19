

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


 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
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

 
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv
    ((0 >= n@pre && 0 <= n@pre && n@pre < 2 && 0 <= v@pre) => ((0 < n@pre) => (((j == 0)&&(k == 0)&&(i == 0)&&(c3 == 10000)&&(c2 == 2000)&&(c1 == 4000)&&(v == v@pre)&&(n == n@pre)) || (k == (n - j) * (v == 0 ? c1 : (v == 1 ? c2 : c3)) && k > 0))) ) &&
((0 >= n@pre && 0 <= n@pre && n@pre < 2 && 0 <= v@pre) => ((0 < n@pre) => (((j == 0)&&(k == 0)&&(i == 0)&&(c3 == 10000)&&(c2 == 2000)&&(c1 == 4000)&&(v == v@pre)&&(n == n@pre)) || (j <= n && k > 0))) ) &&
((0 >= n@pre && 0 <= n@pre && n@pre < 2 && 0 <= v@pre) => ((!(0 < n@pre)) => ((j == 0)&&(k == 0)&&(i == 0)&&(c3 == 10000)&&(c2 == 2000)&&(c1 == 4000)&&(v == v@pre)&&(n == n@pre)))) &&
((0 >= n@pre && 0 <= n@pre && n@pre < 2 && 0 <= v@pre) => (i == 0)) &&
((0 >= n@pre && 0 <= n@pre && n@pre < 2 && 0 <= v@pre) => (c3 == 10000)) &&
((0 >= n@pre && 0 <= n@pre && n@pre < 2 && 0 <= v@pre) => (c2 == 2000)) &&
((0 >= n@pre && 0 <= n@pre && n@pre < 2 && 0 <= v@pre) => (c1 == 4000)) &&
((0 >= n@pre && 0 <= n@pre && n@pre < 2 && 0 <= v@pre) => (v == v@pre)) &&
((0 >= n@pre && 0 <= n@pre && n@pre < 2 && 0 <= v@pre) => (n == n@pre))
    */
                while( j < n ) {
    /*@ Inv
    (assert k > 0)
    */
    j++;
    k--;
  }

}