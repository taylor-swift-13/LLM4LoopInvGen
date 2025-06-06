
int unknown1()
/*@ Require emp 
   Ensure __return <= INT_MAX && __return > INT_MIN
*/ ;
int unknown2()
/*@ Require emp 
   Ensure __return <= INT_MAX && __return > INT_MIN
*/ ;
int unknown3()
/*@ Require emp 
   Ensure __return <= INT_MAX && __return > INT_MIN
*/ ;



void foo(int pvlen) 
/*@ Require emp 
   Ensure emp
*/ 
    {
 
  int t;
  int k = 0;
  int n;
  int i = 0;

 
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (unknown1()){
    i = i + 1;
  
  if (i > pvlen) {
    pvlen = i;
  } else {

  }
}
  i = 0;

 
 
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv
    (((i == 0)&&(k == 0)&&(pvlen == pvlen@pre)) || (k == i) ) &&
(((i == 0)&&(k == 0)&&(pvlen == pvlen@pre)) || (i >= 0) ) &&
(k >= 0)
    */
                while (unknown2()) {
    t = i;
    i = i + 1;
    k = k + 1;
  }

 
  /*@ Print user assertion at number LoopEntry_2*/ 
/*@ Inv
    (i >= 0)
    */
                while (unknown3()){
      ;
  }

  int j = 0;
  n = i;
  
 
  /*@ Print user assertion at number LoopEntry_3*/ 
/*@ Inv
    (j >= 0)
    */
                while (1) {
    
    k = k - 1;
    i = i - 1;
    j = j + 1;
    if (j < n) {
    } else {
      break;
    }
    /*@ Inv
    (assert k >= 0)
    */
  }
}
