#include<stdio.h>

void Check1 () {
  union check {
    int a;
    char b;

  }test;
  test.a = 1;
  if ( test.b  ) {
    printf ("是小端字节序\n");
    return ;

  }
  printf ("是大端字节序\n");
  return;

}

void Check () {
  int a = 1;
  if ( *((char*)&a)  ) {
    printf ("是小端字节序\n");
    return;

  }
  printf ("是大端字节序\n");
  return;

}

int main () {
  Check ();
  Check1();
  return 0;

}
