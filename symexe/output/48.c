
/*@Inv
  (\at(n, Pre) > 0) ==> (((c == 0) && (n == \at(n, Pre))) || (c < \at(n, Pre))) &&
  (\at(n, Pre) > 0) ==> (n == \at(n, Pre))
*/
while (1) {
    if(c != n) {
        c = c + 1;
    }
    else {
        c = 1;
    }
    /*@ assert (c == n) ==> (n > - 1); */
}
