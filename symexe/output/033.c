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

void foo(int k)
 
/*@ Require emp 
   Ensure emp
*/ 
    {
  int z = k;
  int x = 0;
  int y = 0;

 
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while(unknown1())
  {
    int c = 0;
   
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv emp */ /*1*/ 
 while(unknown2())
    {
      if(z==k+y-c)
      {
        x++;
        y++;
        c++;
      }else
      {
        x++;
        y--;
        c++;
      }
    }

   
  /*@ Print user assertion at number LoopEntry_2*/ 
/*@ Inv emp */ /*2*/ 
 while(unknown3())
    {
      x--;
      y--;
    }
    z=k+y;
  }

  /*@  x==y */
}
