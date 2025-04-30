
/*@Inv
  (\at(n, Pre) > 0) ==> (((c == 0) && (n == \at(n, Pre))) || (c > n)) &&
  (\at(n, Pre) > 0) ==> (n == \at(n, Pre))
*/
while (1) {
    if (c > n) {
        c = c + 1;
    } else if (c == n) {
        c = 1;
    }
    
    /*@ assert ((c < 0) && (c > n)) ==> (c == n); */
}
