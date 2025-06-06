

void foo(int k)
/*@
Require 0 <= k && k <= 1
Ensure emp
*/ {
    int i,j;
    i = 1;
    j = 1;
   

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 <= k@pre && k@pre <= 1) => (((j == 1)&&(i == 1)&&(k == k@pre)) || (k == k@pre - (i - 1))) ) &&
((0 <= k@pre && k@pre <= 1) => (((j == 1)&&(i == 1)&&(k == k@pre)) || (i >= 1 && i <= 1000000)) ) &&
((0 <= k@pre && k@pre <= 1) => (((j == 1)&&(i == 1)&&(k == k@pre)) || (j == 1 + (i-1) * k@pre - ((i-1)*(i-2))/2)) )
    */
    
    while (i < 1000000) {
        i = i + 1;
        j = j + k;
        k = k - 1;
        /*@ assert 1 <= i + k && i + k <= 2 && i >= 1;*/
    }

}