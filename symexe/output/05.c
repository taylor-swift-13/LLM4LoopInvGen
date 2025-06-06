
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
/*@ Inv
    (((i == 0)&&(j == 0)&&(y == 0)&&(x == 0)&&(flag == flag@pre)) || (j >= i && x == i && y == j)) &&
(((i == 0)&&(j == 0)&&(y == 0)&&(x == 0)&&(flag == flag@pre)) || (j >= i && x == i && y == j)) &&
(((i == 0)&&(j == 0)&&(y == 0)&&(x == 0)&&(flag == flag@pre)) || (j >= i && x == i && y == j)) &&
(((i == 0)&&(j == 0)&&(y == 0)&&(x == 0)&&(flag == flag@pre)) || (j >= i && x == i && y == j)) &&
(flag == flag@pre)
    */
    
    while (unknown())
    {
        x++;
        y++;
        i += x;
        j += y;
        if (flag){
            j += 1;
        }
    } 
	/*@  j >= i */
	
}