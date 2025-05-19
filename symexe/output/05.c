
int unknown()
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
/*@ Inv emp */ /*0*/ 
 while(unknown())
	{
	  x++;
	  y++;
	  i += x;
	  j += y;
	  if (flag){
	  	j+=1;
      }
	} 
	/*@  j >= i */
	
}