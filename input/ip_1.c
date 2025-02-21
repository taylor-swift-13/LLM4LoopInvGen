#include "verification_stdlib.h"
#include "verification_list.h"
#include "int_array_def.h"
#include "sll_def.h"

int foo(int *t,int len)
/*@ With l
    Require 0 < len && len < 100 && store_int_array(t, len, l) && (forall (i: Z), (0 <= i && i < len) => (0 <= l[i] && l[i] < 100))
    Ensure __return == 0 
*/
{   


    int i;


    for (i=0;i<len;i++) {
        t[i] = 1;
    }

    return 0;

}