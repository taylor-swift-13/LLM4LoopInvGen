
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

 
  while(unknown1())
  {
    
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
