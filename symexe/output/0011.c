

void foo(int n0, int n1) 
/*@
Require INT_MIN < n0 && n0 < INT_MAX && INT_MIN < n1 && n1 < INT_MAX
Ensure emp
*/{
 
  int i0 = 0;
  int k = 0;
 

 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((INT_MIN < n0@pre && n0@pre < INT_MAX && INT_MIN < n1@pre && n1@pre < INT_MAX) => 
                    ((0 < n0@pre) => 
                      (((k == 0)&&(i0 == 0)&&(n1 == n1@pre)&&(n0 == n0@pre)) || 
                      (i0 <= n0))
                    )) &&
((INT_MIN < n0@pre && n0@pre < INT_MAX && INT_MIN < n1@pre && n1@pre < INT_MAX) => 
                    ((0 < n0@pre) => 
                      (((k == 0)&&(i0 == 0)&&(n1 == n1@pre)&&(n0 == n0@pre)) || 
                      (k == i0))
                    )) &&
((INT_MIN < n0@pre && n0@pre < INT_MAX && INT_MIN < n1@pre && n1@pre < INT_MAX) => 
                    ((! (0 < n0@pre)) => 
                      ((k == 0)&&(i0 == 0)&&(n1 == n1@pre)&&(n0 == n0@pre))
                    )) &&
((INT_MIN < n0@pre && n0@pre < INT_MAX && INT_MIN < n1@pre && n1@pre < INT_MAX) => 
                    (n1 == n1@pre)) &&
((INT_MIN < n0@pre && n0@pre < INT_MAX && INT_MIN < n1@pre && n1@pre < INT_MAX) => 
                    (n0 == n0@pre))
    */
    
  while (i0 < n0) {
    i0++;
    k++;
  }

  int i1 = 0;
 
 
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv
    ((k == i0 + i1) && (INT_MIN < n0@pre && n0@pre < INT_MAX && INT_MIN < n1@pre && n1@pre < INT_MAX => !(0 < n0@pre) => k == 0 && i0 == 0 && n1 == n1@pre && n0 == n0@pre) && (INT_MIN < n0@pre && n0@pre < INT_MAX && INT_MIN < n1@pre && n1@pre < INT_MAX => n1 == n1@pre) && (INT_MIN < n0@pre && n0@pre < INT_MAX && INT_MIN < n1@pre && n1@pre < INT_MAX => n0 == n0@pre) && INT_MIN < n0@pre && n0@pre < INT_MAX && INT_MIN < n1@pre && n1@pre < INT_MAX) => ((0 < n1) => (((i1 <= n1))) || (i1 == 0)) ) &&
((k == i0 + i1) && (INT_MIN < n0@pre && n0@pre < INT_MAX && INT_MIN < n1@pre && n1@pre < INT_MAX => !(0 < n0@pre) => k == 0 && i0 == 0 && n1 == n1@pre && n0 == n0@pre) && (INT_MIN < n0@pre && n0@pre < INT_MAX && INT_MIN < n1@pre && n1@pre < INT_MAX => n1 == n1@pre) && (INT_MIN < n0@pre && n0@pre < INT_MAX && INT_MIN < n1@pre && n1@pre < INT_MAX => n0 == n0@pre) && INT_MIN < n0@pre && n0@pre < INT_MAX && INT_MIN < n1@pre && n1@pre < INT_MAX) => ((!(0 < n1)) => ((i1 == 0)))) &&
((i0 <= n0) && (INT_MIN < n0@pre && n0@pre < INT_MAX && INT_MIN < n1@pre && n1@pre < INT_MAX => 0 < n0@pre => k == 0 && i0 == 0 && n1 == n1@pre) => ((!(i1 < n1)) => ((n0 == n0@pre)))) &&
((i0 <= n0) && (INT_MIN < n0@pre && n0@pre < INT_MAX && INT_MIN < n1@pre && n1@pre < INT_MAX => 0 < n0@pre => k == 0 && i0 == 0 && n1 == n1@pre) => (n0 == n0@pre)) &&
((i0 >= n0 && (INT_MIN < n0@pre && n0@pre < INT_MAX && INT_MIN < n1@pre && n1@pre < INT_MAX => 0 < n0@pre => k == 0 && i0 == 0 && n1 == n1@pre) => ((!(i1 < n1)) => ((n0 == n0@pre)))) &&
((i0 >= n0 && (INT_MIN < n0@pre && n0@pre < INT_MAX && INT_MIN < n1@pre && n1@pre < INT_MAX => 0 < n0@pre => k == 0 && i0 == 0 && n1 == n1@pre) => (n0 == n0@pre))
    */
    
  while (i1 < n1) {
    i1++;
    k++;
  }

  int j1 = 0;
  
 
  /*@ Print user assertion at number LoopEntry_2*/ 
/*@ Inv
    ((k == i0 + i1 - j1) && (INT_MIN < n0@pre && n0@pre < INT_MAX && INT_MIN < n1@pre && n1@pre < INT_MAX) => ((j1 <= n0 + n1)) ) &&
((k >= 0))
    */
    
  while (j1 < n0 + n1) {
    /*@ assert k > 0; */
    j1++;
    k--;
  }
}