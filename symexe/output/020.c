
int unknown()
/*@ Require emp 
   Ensure __return <= INT_MAX && __return > INT_MIN
*/;


void foo(int x, int y, int k, int j, int i, int n)  
/*@ Require (x+y == k) && n > 0
   Ensure emp
*/ 
    {
 
  int m = 0;
  j = 0;
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((x@pre + y@pre == k@pre && n@pre > 0) => ((0 < n@pre) => (((m == 0)&&(n == n@pre)&&(i == i@pre)&&(j == 0)&&(k == k@pre)&&(y == y@pre)&&(x == x@pre)) || (j <= n))) ) &&
((x@pre + y@pre == k@pre && n@pre > 0) => ((0 < n@pre) => (((m == 0)&&(n == n@pre)&&(i == i@pre)&&(j == 0)&&(k == k@pre)&&(y == y@pre)&&(x == x@pre)) || (x + y == k))) ) &&
((x@pre + y@pre == k@pre && n@pre > 0) => ((0 < n@pre) => (((m == 0)&&(n == n@pre)&&(i == i@pre)&&(j == 0)&&(k == k@pre)&&(y == y@pre)&&(x == x@pre)) || (m < n))) ) &&
((x@pre + y@pre == k@pre && n@pre > 0) => ((!(0 < n@pre)) => ((m == 0)&&(n == n@pre)&&(i == i@pre)&&(j == 0)&&(k == k@pre)&&(y == y@pre)&&(x == x@pre)))) &&
((x@pre + y@pre == k@pre && n@pre > 0) => (n == n@pre)) &&
((x@pre + y@pre == k@pre && n@pre > 0) => (i == i@pre)) &&
((x@pre + y@pre == k@pre && n@pre > 0) => (k == k@pre))
    */
                while (j < n) {
    if (j == i) {
      x++;
      y--;
    } else {
      y++;
      x--;
    }
    if (unknown()){
       m = j;
    }
    j++;
  }
  /*@ (x + y) == k */
  
  /*@ (n > 0) => (0 <= m && m < n)*/
  

}