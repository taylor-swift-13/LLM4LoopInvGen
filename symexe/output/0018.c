
int unknown1();


void foo(int flag) 
/*@
Require emp
Ensure emp
*/{
    unsigned int i,j,a,b;
    a = 0;
    b = 0;
    j = 1;
    if (flag) {
        i = 0;
    } else {
        i = 1;
    }

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((flag@pre == 0) => (((b == 0)&&(a == 0)&&(j == 1)&&(i == 1)&&(flag == flag@pre)) || (i > 1)) ) &&
((flag@pre == 0) => (((b == 0)&&(a == 0)&&(j == 1)&&(i == 1)&&(flag == flag@pre)) || (j >= 1)) ) &&
((flag@pre == 0) => (((b == 0)&&(a == 0)&&(j == 1)&&(i == 1)&&(flag == flag@pre)) || (a >= 0)) ) &&
((flag@pre == 0) => (((b == 0)&&(a == 0)&&(j == 1)&&(i == 1)&&(flag == flag@pre)) || (b >= 0)) ) &&
((flag@pre == 0) => (flag == flag@pre)) &&
((flag@pre != 0) => (((b == 0)&&(a == 0)&&(j == 1)&&(i == 0)&&(flag == flag@pre)) || (i >= 0)) ) &&
((flag@pre != 0) => (((b == 0)&&(a == 0)&&(j == 1)&&(i == 0)&&(flag == flag@pre)) || (j >= 1)) ) &&
((flag@pre != 0) => (((b == 0)&&(a == 0)&&(j == 1)&&(i == 0)&&(flag == flag@pre)) || (a >= 0)) ) &&
((flag@pre != 0) => (((b == 0)&&(a == 0)&&(j == 1)&&(i == 0)&&(flag == flag@pre)) || (b >= 0)) ) &&
((flag@pre != 0) => (flag == flag@pre))
    */
    
    while (unknown1()) {
        a++;
        b += (j - i);
        i += 2;
        if (i%2 == 0) {
            j += 2;
        } else {
            j++;
        }
    }
    if (flag) {
        /*@ a == b*/
    }

}