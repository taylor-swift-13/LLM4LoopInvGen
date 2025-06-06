

void foo() 
/*@
Require emp
Ensure emp
*/
{
    int i,j;
    i = 1;
    j = 10;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (((j == 10)&&(i == 1)) || (i == 2*(10-j) + 1) ) &&
(((j == 10)&&(i == 1)) || (j == 10 - ((i-1)/2)) ) &&
(j >= 6)
    */
                while (j >= i) {
        i = i + 2;
        j = -1 + j;
    }

    /*@j == 6*/

}