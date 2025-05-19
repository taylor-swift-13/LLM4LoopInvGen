int unknown1()
/*@ Require emp 
Ensure __return <= INT_MAX && __return > INT_MIN
*/;
int unknown2()
/*@ Require emp 
Ensure __return <= INT_MAX && __return > INT_MIN
*/;


void foo(int flag)  
/*@ Require flag > 0
   Ensure emp
*/ 
    {
  int i, j, k;
  j = 1;
  if (flag) {
    i = 0;
  } else {
    i = 1;
  }

 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (unknown1()) {
    i += 2;
    if (i % 2 == 0) {
      j += 2;
    } else j++;
  }

  int a = 0;
  int b = 0;

 
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv
    (((b == 0)&&(a == 0)&&(j >= 1)&&(i >= 0)&&(flag == flag@pre)) || (b == (j - i) * a)) &&
(j >= 1) &&
(i >= 0) &&
(flag == flag@pre)
    */
                while (unknown2()) {
    a++;
    b += (j - i);
  }
  /*@ (flag!=0) => (a==b) */
}