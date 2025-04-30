
int unknown()
/*@ Require emp 
   Ensure __return <= INT_MAX && __return > INT_MIN
*/;

void foo(int i,int j,int k,int n,int m)  
/*@ Require m + 1 < n
   Ensure emp
*/ 
    {

  i = 0;
  for (i = 0; i < n; i += 4) {
    j = i ;
    for (j = i; j < m;) {
        
      if (unknown()) {
        /*@  j >= 0*/
        j++;
        k = 0;
        while (k < j) {
          k++;
        }
      } else {
        /*@  n + j + 5 > i*/
        j += 2;
      }
    }
  }
}