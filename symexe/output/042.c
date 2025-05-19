int unknown()
/*@ Require emp 
   Ensure __return <= INT_MAX && __return > INT_MIN
*/;

void foo(int flag)  
/*@ Require emp 
   Ensure emp
*/ 
    {
  int x = 1;
  int y = 1;
  int a;

  if (flag)
    a = 0;
  else
    a = 1;

  
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((flag@pre == 0) => (((a == 1)&&(y == 1)&&(x == 1)&&(flag == flag@pre)) || (x >= 1)) ) &&
((flag@pre == 0) => (((a == 1)&&(y == 1)&&(x == 1)&&(flag == flag@pre)) || (y >= 1)) ) &&
((flag@pre == 0) => (((a == 1)&&(y == 1)&&(x == 1)&&(flag == flag@pre)) || (a >= 1)) ) &&
((flag@pre == 0) => (flag == flag@pre)) &&
((flag@pre != 0) => (((a == 0)&&(y == 1)&&(x == 1)&&(flag == flag@pre)) || (x >= 1)) ) &&
((flag@pre != 0) => (((a == 0)&&(y == 1)&&(x == 1)&&(flag == flag@pre)) || (y >= 1)) ) &&
((flag@pre != 0) => (((a == 0)&&(y == 1)&&(x == 1)&&(flag == flag@pre)) || (a >= 0)) ) &&
((flag@pre != 0) => (flag == flag@pre)) &&
((flag == flag@pre) => (a % 2 == (flag ? x + y : x + y + 1) % 2))
    */
  while (unknown()) {
    if (flag) {
      a = x + y;
      x++;
    } else {
      a = x + y + 1;
      y++;
    }
    if (a % 2 == 1)
      y++;
    else
      x++;
  }
  
  if (flag)
    a++;
  /*@  a % 2 == 1 */
}