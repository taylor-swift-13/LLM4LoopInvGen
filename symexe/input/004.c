

void foo() 
/*@
Require emp
Ensure emp
*/
{
    int i,j;
    i = 1;
    j = 10;

    while (j >= i) {
        i = i + 2;
        j = -1 + j;
    }

    /*@j == 6*/

}