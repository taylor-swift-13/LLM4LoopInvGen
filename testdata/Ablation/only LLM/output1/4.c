
void foo(int y, int z)
{
    int x = 0;   

    /*@ loop invariant 0 <= x <= 500;
        loop invariant z >= y;
        loop variant 500 - x;
    */
    while(x < 500) {
        x += 1;
        if(z <= y) {
            y = z;
        }
    }

    /*@ assert z >= y; */
}
