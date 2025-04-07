int unknown();

/*@ requires n > 0; */
void foo(int n,int v1,int v2,int v3)  {

    int c = 0;

    
            /*@
              loop invariant (\at(n, Pre) > 0) ==> (c >= 0);
              loop invariant (\at(n, Pre) > 0) ==> (c <= \at(n, Pre));
              loop invariant (\at(n, Pre) > 0) ==> (v3 == \at(v3, Pre));
              loop invariant (\at(n, Pre) > 0) ==> (v2 == \at(v2, Pre));
              loop invariant (\at(n, Pre) > 0) ==> (v1 == \at(v1, Pre));
              loop invariant (\at(n, Pre) > 0) ==> (n == \at(n, Pre));
            */
            while (unknown()) {
                {
                    if (unknown()) {
                        if (c != n) { // Changed from \at(n, Pre) to n
                            c = c + 1;
                        }
                    } else {
                        if (c == n) {
                            c = 1;
                        }
                    }
                }
            }

           
     /*@ assert (c == n) ==> (n > - 1); */
    

  

}