
/*@Inv
  (c == 0) || (c >= 1 && c <= 4)
*/
while (1) {
    if (c != 4) {
        c = c + 1;
    } else {
        c = 1;
    }
    
    /*@ assert (c != 4) ==> (c >= 0); */
}
