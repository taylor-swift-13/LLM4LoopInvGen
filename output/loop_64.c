void foo(int j,int c,int t) {

    int i = 0;




/*@
  loop invariant (1) ==> (i >= 0);
  loop invariant (1) ==> (t == \at(t, Pre) || t == (\at(c, Pre)) - 48);
  loop invariant (1) ==> (j == \at(j, Pre) || j == 2 * i - t);
  loop invariant (1) ==> (i == 0 || i == 2 * i - t + (\at(c, Pre)) - 48);
  loop invariant (1) ==> (((\at(c, Pre)) < 57) ==> ((\at(c, Pre)) > 48)) ==> (t == \at(t, Pre) || t == (\at(c, Pre)) - 48);
  loop invariant (1) ==> ((j == \at(j, Pre)) || (j == 2 * i - t));
  loop invariant c == \at(c, Pre);
*/
while(1) {
    if(c > 48) {
        if (c < 57) {
            j = i + i;
            t = c - 48;
            i = j + t;
        }
    }

    /*@ assert i >= 0; */
}
 


}