#include "lab7.h"

int readInitialLength()
{
    int length=0;
    do 
    {
     printf("Enter array length ");
     scanf("%d", &length);

     if (length<= 1)
     {
       printf("Invalid\n");
     }
    } while(length <= 1);
    return length;

}
int *createAndFill(int length)
{
    int x;
    int * myArray = (int*)calloc(length, sizeof(int));; //malloc(size_t __size)
                      // calloc
    
    for (x=0; x<length;x++) 
    {
      printf("Enter value ");
      scanf("%d", &myArray[x]);
    }

    return myArray;

}
int menu()
{
    int choice=4;
    do
    {
    printf("The menu choices are\n");
    printf("1. printSortedArray \n");
    printf("2. addItem\n");
    printf("3. readValue\n");
    printf("4. Quit the program\n");
    printf("Choose: ");
    scanf("%d", &choice);

    if (choice == '4')
    {
      printf("Good Bye\n");
    }
    if (choice < 1 || choice >4)
    {
      printf("Invalid choice \n");
    }
 
    
    }while (choice < 1 || choice > 4);
  

  return choice;
}











void printSortedArray(int* myArray, int length)
{
  selectionSort(myArray,length);
  printf("Array: \n");
  printf("[");
  for (int i=0; i< length; i++)
  {
    printf("%d, ", myArray[i]);
  
	
    
  }
  printf("] \n");

   
}

int *addItem(int* length, int* myArray)
{
  int a, val1;
  int * myArray1 = (int *)malloc((*length + 1) * sizeof(int));

  printf("Enter value to add in array: ");
  scanf("%d", &val1);

  for (a=0; a < *length+1; a++)
  {
    myArray1[a] = myArray[a];   
  }
  free(myArray);

  myArray1[*length] = val1;
  printf("[");

  for (a=0; a< *length + 1; a++)
  {
    
    printf("%d ", *(myArray1 + a));
    
  }
  *length = *length + 1;

  printf("]\n");

return myArray1;

}
int readValue()
{
    int value=0;
    printf("Enter a value to read ");
    scanf("%d", &value);
    return value;
}

void printIfFound(int value, int* myArray, int length)
{
  for (int i=0; i<length; i++)
    {
     if (value == myArray[i])
     {
       printf("Value found: %d\n", value);
       printf("Position: %d\n", i);
       return;
     }
    }
  printf("Value not found \n");
     
     
     
     
     

} 

void cleanUp(int* myArray)
{
    free(myArray);
}

void selectionSort(int* myArray, int length)
{
  int start, search, min;
  int temp;

  for(start = 0; start < length - 1; start++)
  {
    min = start;
    for(search = start + 1; search < length; search++)
    {
      if(myArray[search] < myArray[min])
        min = search;
    } // end for search
  
    temp = myArray[min];
    myArray[min] = myArray[start];
    myArray[start] = temp;
  }// end for start
}// end function