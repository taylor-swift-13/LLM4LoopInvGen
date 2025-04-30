
/*@Inv
  (n@pre > 0 && k@pre > n@pre) ==> ((0 < n@pre) ==> (((j == 0)&&(k == k@pre)&&(n == n@pre)) || (k == k@pre - j))) &&
  (n@pre > 0 && k@pre > n@pre) ==> ((0 < n@pre) ==> (((j == 0)&&(k == k@pre)&&(n == n@pre)) || (0 <= j && j <= n@pre))) &&
  (n@pre > 0 && k@pre > n@pre) ==> ((!(0 < n@pre)) ==> ((j == 0)&&(k == k@pre)&&(n == n@pre))) &&
  (n@pre > 0 && k@pre > n@pre) ==> (n == n@pre)
*/
while( j < n ) {
  j++;
  k--;
}
