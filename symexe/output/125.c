
/*@Inv
  (i >= 0) && (j >= 0) && (y >= 0) && (x >= 0) &&
  (x >= 0) => (i >= x@pre - x) && (j >= y@pre - (x@pre - x)) &&
  (x < 0) => (i >= x@pre - (x@pre - x)) && (j >= y@pre - (x@pre - x)) &&
  j == y@pre &&
  i >= x@pre - (x@pre - x)
*/
while (x != 0) {
    x  = x - 1;
    y  = y - 1;
}

/*@ assert (y != 0) ==> (i != j); */
