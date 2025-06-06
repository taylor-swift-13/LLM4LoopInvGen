int unknown();


void foo()
 
/*@ Require emp 
   Ensure emp
*/ 
    {
	int i = 1;
	int j = 0;
	int z = i - j;
	int x = 0;
	int y = 0;
	int w = 0;



 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (((w == 0)&&(y == 0)&&(x == 0)&&(z == 1 - 0)&&(j == 0)&&(i == 1)) || (z == y * (y - 1)/ 2 + y * x + w * (y + 1) / 2 + 1) ) &&
(((w == 0)&&(y == 0)&&(x == 0)&&(z == 1 - 0)&&(j == 0)&&(i == 1)) || (x == y / 2) ) &&
(((w == 0)&&(y == 0)&&(x == 0)&&(z == 1 - 0)&&(j == 0)&&(i == 1)) || (y == y) ) &&
(((w == 0)&&(y == 0)&&(x == 0)&&(z == 1 - 0)&&(j == 0)&&(i == 1)) || (w == 2 * y) ) &&
(j == 0) &&
(i == 1)
    */
    
    while(unknown()) 
    {
        z += x + y + w;
        y++;
        if (z % 2 == 1) 
          x++;
        w += 2; 
    }

	/*@  x ==y */
}
