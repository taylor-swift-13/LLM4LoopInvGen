
void foo(int size,int v1,int v2,int v3)
/*@  Require size >= 1
     Ensure emp
*/ {
 
  int i = 1;
  int sn = 0;
  
   
  while (i <= size) {

    i  = (i + 1);
    sn  = (sn + 1);
    
  }

  if(sn!=size){
  /*@ (sn == 0)*/
  }

}