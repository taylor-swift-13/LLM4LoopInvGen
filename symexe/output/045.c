
int unknown1()
/*@ Require emp 
   Ensure __return <= INT_MAX && __return > INT_MIN
*/;
int unknown2()
/*@ Require emp 
   Ensure __return <= INT_MAX && __return > INT_MIN
*/;
int unknown3()
/*@ Require emp 
   Ensure __return <= INT_MAX && __return > INT_MIN
*/;


void foo(int flag)  
/*@ Require emp 
   Ensure emp
*/ 
    {
  int x = 0;
  int y = 0;
  int j = 0;
  int i = 0;

 
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (((i == 0)&&(j == 0)&&(y == 0)&&(x == 0)&&(flag == flag@pre)) || (x == y)) &&
(((i == 0)&&(j == 0)&&(y == 0)&&(x == 0)&&(flag == flag@pre)) || (y == x)) &&
(((i == 0)&&(j == 0)&&(y == 0)&&(x == 0)&&(flag == flag@pre)) || (j == i + x * (flag ? 1 : 0))) &&
(((i == 0)&&(j == 0)&&(y == 0)&&(x == 0)&&(flag == flag@pre)) || (i == x * (x + 1) / 2)) &&
(flag == flag@pre)
    */
  while (unknown1()) {
    x++;
    y++;
    i += x;
    j += y;
    if (flag) {
      j += 1;
    }
  }
  if (j >= i)
    x = y;
  else
    x = y + 1;

  int w = 1;
  int z = 0;
  
 
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv emp */ /*1*/ 
 while (unknown2()) {
   
   
  /*@ Print user assertion at number LoopEntry_2*/ 
/*@ Inv emp */ /*2*/ 
 while (unknown3()) {
      if (w % 2 == 1)
        x++;
      if (z % 2 == 0)
        y++;
    }
    z = x + y;
    w = z + 1;
  }
  /*@  x == y */
}