#include <stdio.h>
#include <stdlib.h>

int menu(void);

void add(int item);

int insert(int index, int item);

int size();

int removeL(int index);

int set(int index, int item);

int get(int index);

int sizeArr = 0;
int* arr = NULL;

int main()
{
  while (1)
  {
    int sw = menu();
    if (sw == 1)
    {
      int temp = 0;
      printf("\nEnter adding value: ");
      scanf("%d", &temp);
      add(temp);
      for (int i = 0; i < size(); i++)
      {
        printf("\narr[%d] == %d", i, arr[i]);
      }
    }
    else
    {
      if (sw == 2)
      {
        int tempInd = -1;
        printf("\nEnter index (from 0 to %d included): ", size());
        scanf("%d", &tempInd);
        int tempVal = 0;
        printf("\nEnter adding value: ");
        scanf("%d", &tempVal);

        if (insert(tempInd, tempVal) == -1)
        {
          printf("\nInvalid index!");
          continue;
        }

        for (int i = 0; i < size(); i++)
        {
          printf("\narr[%d] == %d", i, arr[i]);
        }
      }
      else
      {
        if (sw == 3)
        {
          printf("\nCurrent array size: %d", size());
        }
        else
        {
          if (sw == 4)
          {
            if (size() == 0)
            {
              printf("\nNothing to remove!");
              continue;
            }
            int tempInd = -1;
            printf("\nEnter element index to remove (from 0 to %d included): ", size() - 1);
            scanf("%d", &tempInd);
            if (removeL(tempInd) == -1)
            {
              printf("\nInvalid index!");
              continue;
            }

            if (size() == 0)
            {
              printf("\nArray was fully cleared.");
              continue;
            }
            
            for (int i = 0; i < size(); i++)
            {
              printf("\narr[%d] == %d", i, arr[i]);
            }
          }
          else
          {
            if (sw == 5)
            {
              if (size() == 0)
              {
                printf("\nNothing to change, array is empty!");
                continue;
              }
              int tempInd = -1;
              printf("\nEnter element index to set new value (from 0 to %d included): ", size() - 1);
              scanf("%d", &tempInd);

              int tempVal = 0;
              printf("\nEnter new value for element: ");
              scanf("%d", &tempVal);

              if (set(tempInd, tempVal) == -1)
              {
                printf("\nInvalid index!");
                continue;
              }

              for (int i = 0; i < size(); i++)
              {
                printf("\narr[%d] == %d", i, arr[i]);
              }
            }
            else
            {
              if (sw == 6)
              {
                if (size() == 0)
                {
                  printf("\nNothing to show, array is empty!");
                  continue;
                }
                int tempInd = -1;
                printf("\nEnter element index to get its value (from 0 to %d included): ", size() - 1);
                scanf("%d", &tempInd);

                int tempRes = get(tempInd);
                if (tempRes == 285761)
                {
                  printf("\nInvalid index!");
                  continue;
                }

                printf("\nRequested element with %d-index: %d", tempInd, tempRes);
              }
              else
              {
                return 0;
              }
            }
          }
        }
      }
    }
  }
}

int menu(void)
{
  int sw = 0;
  do
  {
    printf("\n\nTesting Array List:");
    printf("\n1. Add(item) method;\n2. insert(index, item) method;\n3. size() method;\n4. remove(index) method;\n5. set(index, item) method;\n6. get(index) method;\n0. End testing.\n");
    scanf("%d", &sw);
  } while (sw < 0 || sw > 6);
  return sw;
}

void add(int item)
{
  if (arr == NULL)
  {
    arr = (int*)calloc(1, sizeof(int));
    arr[0] = item;
    sizeArr++;
    return;
  }
  int *tempArr = (int*)calloc(size() + 1, sizeof(int));
  for (int i = 0; i < size(); i++)
  {
    tempArr[i] = arr[i];
  }
  tempArr[size()] = item;
  free(arr);
  arr = tempArr;
  tempArr = NULL;
  sizeArr++;
}

int insert(int index, int item)
{
  if (index > size() + 1 || index < 0)
  {
    return -1;
  }

  if (index == size())
  {
    add(item);
    return 0;
  }

  int *tempArr = (int*)calloc(size() + 1, sizeof(int));

  if (index == 0)
  {

    tempArr[0] = item;
    for (int i = 0; i < size(); i++)
    {
      tempArr[i + 1] = arr[i];
    }
  }
  else
  {
    for (int i = 0; i < index; i++)
    {
      tempArr[i] = arr[i];
    }
    tempArr[index] = item;
    for (int i = index; i < size(); i++)
    {
      tempArr[i + 1] = arr[i];
    }
  }

  free(arr);
  arr = tempArr;
  tempArr = NULL;
  sizeArr++;
}

int size()
{
  return sizeArr;
}

int removeL(int index)
{
  if (index > size() - 1 || index < 0)
  {
    return -1;
  }

  if (size() == 1)
  {
    free(arr);
    arr = NULL;
    sizeArr--;
    return 0;
  }

  int *tempArr = (int *)calloc(size() - 1, sizeof(int));

  for (int i = 0; i < index; i++)
  {
    tempArr[i] = arr[i];
  }
  for (int i = index + 1; i < size(); i++)
  {
    tempArr[i - 1] = arr[i];
  }

  free(arr);
  arr = tempArr;
  tempArr = NULL;
  sizeArr--;
}

int set(int index, int item)
{
  if (index > size() - 1 || index < 0)
  {
    return -1;
  }
  arr[index] = item;
}

int get(int index)
{
  if (index > size() - 1 || index < 0)
  {
    return 285761;
  }
  return arr[index];
}
