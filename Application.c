#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  FILE *fp;
  char broj[5];
  int x =0;
  char znak = ';';
  
  while(1)
    {
      //  fp = fopen("/dev/fifo" , "r");
      //      if(fp == NULL)
      //	{
      //  puts("Problem pri otvaranju /dev/fifo");
      //  return -1;
      //	}
      printf("MENI:\n");
      printf("1: Upisi u FIFO bafer\n");
      printf("2: Procitaj iz FIFO bafera\n");
      printf("3: Izadji \n");

      scanf("%d", &x);

      switch(x)
	{
	case 1:
	  {
	    int uslov1 = 1;
	    int uslov2 = 1;
	    printf("Unesi vrednost: \n");
	    fp = fopen ("/dev/fifo","w");
	    if(fp == NULL)
	      {
		puts("Problem pri otvaranju /dev/fifo");
		return -1;
	      }
	    while(uslov2)
	      {
		printf("Unesi broj: ");
		scanf("%s", broj);
		if(uslov1)
		  {
		    fprintf(fp,"%s", broj);
		    uslov1=0;
		  }
		else
		  {
		    if(broj[0] == 'Q')
		      uslov2=0;
		    else
		      fprintf(fp,";%s", broj);
		  }
	      
	      }
	    fputs("\n",fp);
	    if(fclose(fp))
	      {
		puts("Problem pri zatvaranju /dev/fifo");
		return -1;
	      }
	    
	    break;
	  }
	case 2:
	  {
	    char *vr;
	    size_t num_bit = 5;
	    fp = fopen("/dev/fifo","r");
	    if(fp == NULL)
	      {
		puts("Problem pri otvaranju /dev/fifo");
		return -1;
	      }

	    vr = (char*) malloc(num_bit);
	    getline(&vr,&num_bit,fp);
	    printf("Procitana vrednost: %s\n", vr);

	    free(vr);
	    if(fclose(fp))
	      {
		puts("Problem pri zatvaranju /dev/fifo ");
		return -1;
	      }
	    break;
	  }
	case 3:
	  {
	   printf("Izlaz \n\n");
	   /* if(fclose(fp))
	      {
		puts("Problem pri zatvaranju /dev/fifo");
		return -1;
		}*/
	    return 0;
	    break;
	  }
	  
	}
      
      
    }  

  
}  
