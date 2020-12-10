#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  FILE *fp;
  int x =0;
  while(1)
    {
      //  fp = fopen("/dev/fifo" , "r");
      //      if(fp == NULL)
      //	{
      //  puts("Problem pri otvaranju /dev/fifo");
      //  return -1;
      //	}
      printf("MENI:\n\n");
      printf("1: Upisi u FIFO bafer\n\n");
      printf("2: Procitaj iz FIFO bafera\n\n");
      printf("3: Izadji \n\n");

      scanf("%d " , &x);

      switch(x)
	{
	case 1:
	  {
	    printf("Upis: \n");
	    fp = fopen ("/dev/fifo","w");
	    if(fp == NULL)
	      {
		puts("Problem pri otvaranju /dev/fifo");
		return -1;
	      }
	    break;
	  }
	case 2:
	  {
	    printf("Ispis: \n\n");
	    break;
	  }
	case 3:
	  {
	    printf("Izlaz \n\n");
	    if(fclose(fp))
	      {
		puts("Problem pri zatvaranju /dev/fifo");
		return -1;
	      }
	    return 0;
	  }
	  
	}
      
      
    }  

  
}  
