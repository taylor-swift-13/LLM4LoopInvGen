
int unknown1()
/*@ Require emp 
Ensure __return <= INT_MAX && __return > INT_MIN
*/;
int unknown2()
/*@ Require emp 
   Ensure __return <= INT_MAX && __return > INT_MIN
*/;


void foo()
 
/*@ Require emp 
   Ensure emp
*/ 
    {
  int x = 0;
  int y = 0;
  int i = 0;
  int j = 0;

 
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (((j == 0)&&(i == 0)&&(y == 0)&&(x == 0)) || (0 <= x)) &&
(((j == 0)&&(i == 0)&&(y == 0)&&(x == 0)) || (0 <= y)) &&
(((j == 0)&&(i == 0)&&(y == 0)&&(x == 0)) || (i >= j)) &&
(((j == 0)&&(i == 0)&&(y == 0)&&(x == 0)) || (x <= y))
    */
    
  while(unknown1())
  {
    /*@
      loop invariant 0 <= x;
      loop invariant 0 <= y;
      loop invariant i >= j;
      loop invariant x <= y;
    */
    while(unknown2())
    {
      if(x == y){
        i++;
      }else{
        j++;
      }
    }

    if(i >= j)
    {
      x++;
      y++;
    }
    else{
      y++;
    }
  }

  /*@  i >= j */
}
