
/*@Inv
  (x@pre >= y@pre && y@pre >= 0) => (0 <= i && i <= y)
*/
while (unknown()) {
    if (i < y) {
        i = (i + 1);
    }

    /*@ assert (i < 0 && i >= x) ==> (i >= y); */
}
