
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