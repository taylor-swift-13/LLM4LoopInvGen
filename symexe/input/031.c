
int unknown();

void foo(int i,int j,int k,int n,int m)  
/*@ Require m + 1 < n
   Ensure emp
*/ 
    {

 
  for (i = 0; i < n; i += 4) {
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