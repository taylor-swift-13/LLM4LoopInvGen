
/*@Inv
  (\at(n, Pre) > 0) ==> (((c == 0) && (n == \at(n, Pre))) || (c >= 0 && c <= n)) &&
  (\at(n, Pre) > 0) ==> (n == \at(n, Pre))
*/
while (1) {
    if(c == n) {
        c = 1;
    }
    else {
        c = c + 1;
    }
    
    /*@ assert (c == n) ==> (c >= 0); */
}
