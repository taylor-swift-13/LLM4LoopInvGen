
void foo(int *t)
{
    int i;

    /*@
    loop invariant 0 <= i <= 5;
    loop invariant \forall integer j; 0 <= j < i ==> t[j] == 1;
    */
    for (i = 0; i < 5; i++) {
        t[i] = 1;
    }

    /*@ assert \forall integer i; 0 <= i < 5 ==> t[i] == 1;  */
}
