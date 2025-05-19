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

  while (unknown1()) {
    i += 2;
    if (i % 2 == 0) {
      j += 2;
    } else j++;
  }

  int a = 0;
  int b = 0;

  while (unknown2()) {
    a++;
    b += (j - i);
  }
  /*@ (flag!=0) => (a==b) */
}