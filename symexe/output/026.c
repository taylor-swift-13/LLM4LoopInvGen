
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


void main()  
/*@ Require emp 
   Ensure emp
*/ 
{
  int w = 1, z = 0, x = 0, y = 0;
 
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (unknown1()) {
   
   
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv emp */ /*1*/ 
 while (unknown2()) {
      if (w % 2 == 1)
        x++;
      if (z % 2 == 0)
        y++;
    }
   
   
  /*@ Print user assertion at number LoopEntry_2*/ 
/*@ Inv emp */ /*2*/ 
 while (unknown3()) {
      z = x + y;
      w = z + 1;
    }
  }
  /*@  x == y*/
}