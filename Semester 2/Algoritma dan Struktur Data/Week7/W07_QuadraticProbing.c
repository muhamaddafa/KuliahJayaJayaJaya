#include <stdio.h>
#include <conio.h>
#include <windows.h>

int quadraticFunction(int number, int n)
{
  int i, temp;
  temp = n;
  for (i = 0; i < n - 1; i++)
  {
    temp *= n;
  }
  return (number + temp) % 10;
}

int hashFunction(int number)
{
  return number % 10;
}

int main()
{
  int arr[] = {3, 5, 13, 24, 33, 45, 54, 78, 81, 99, 100};
  int hashTable[10];
  int i, n;
  int hashResult, quadraticResult;

  for (i = 0; i < 10; i++)
  {
    hashTable[i] = -1;
  }

  for (i = 0; i < sizeof(arr) / 4; i++)
  {
    hashResult = hashFunction(arr[i]);
    n = 0;
    do
    {
      quadraticResult = quadraticFunction(hashResult, n);
      if (hashTable[quadraticResult] == -1)
      {
        hashTable[quadraticResult] = arr[i];
        break;
      }
      else if (n == sizeof(arr) / 4)
      {
        break;
      }
      else
        n++;
    } while (1);
  }

  for (i = 0; i < 10; i++)
  {
    printf("hashTable[%d] = %d\n", i, hashTable[i]);
  }

  return 0;
}