
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
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (i = 0; i < n; i += 4) {
    j = i ;
   
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv emp */ /*1*/ 
 for (j = i; j < m;) {
        
      if (unknown()) {
        /*@  j >= 0*/
        j++;
        k = 0;
       
  /*@ Print user assertion at number LoopEntry_2*/ 
/*@ Inv emp */ /*2*/ 
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