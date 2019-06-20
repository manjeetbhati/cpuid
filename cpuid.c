#include<stdio.h>
#include<string.h>
#include<stdlib.h>

static inline void native_cpuid(unsigned int *eax, unsigned int *ebx,
                                unsigned int *ecx, unsigned int *edx)
{
        /* ecx is often an input as well as an output. */
        asm volatile("cpuid"
            : "=a" (*eax),
              "=b" (*ebx),
              "=c" (*ecx),
              "=d" (*edx)
            : "0" (*eax), "2" (*ecx));
}

int main(int argc, char *argv[])
{

  unsigned eax, ebx, ecx, edx;


  if (argc < 5){
      printf("You must provide eax, ecx, ebx, edx values in same order\n");
      printf("for example ./cpuid 7 0 0 0\n");
      printf("This calls cpuid with eax=7, ecx=0, ebx=0, edx=0\n");
      return 0;
  }

  eax = atoi(argv[1]); /* processor info and feature bits */
  ecx = atoi(argv[2]); /* processor info and feature bits */
  ebx = atoi(argv[3]); /* processor info and feature bits */
  edx = atoi(argv[4]); /* processor info and feature bits */
  native_cpuid(&eax, &ebx, &ecx, &edx);

  printf("EAX %d\n", eax);
  printf("EBX %d\n", ebx);
  printf("EDX %d\n", edx);
  printf("ECX %d\n", ecx);
  return 0;

}
