#include <stdio.h>

#define MAX 4500

void add(char a1[], char a2[], char ans[])
{
  int carry = 0;
  for (int i = MAX - 1; i >= 0; i--)
  {
    int digit = (a1[i] - '0') + (a2[i] - '0') + carry;
    ans[i] = (digit % 10) + '0';
    carry = digit / 10;
  }
}

void fibo(char a1[], char a2[])
{
  for (int i = MAX - 1; i >= 0; i--)
    a1[i] = a2[i];
}

char f1[MAX];
char f2[MAX];
char ans[MAX];

int main()
{

  for (int i = 0; i < MAX; i++)
  {
    f1[i] = f2[i] = ans[i] = '0';
  }
  f2[MAX - 1] = '1';

  int n;
  scanf("%d", &n);

  if (n == 0 || n == 1)
  {
    printf("%c", n + '0');
  }
  else
  {
    for (int i = 2; i <= n; i++)
    {
      add(f1, f2, ans);
      fibo(f1, f2);
      fibo(f2, ans);
    }

    int n = 0;
    for (int i = 0; i < MAX; i++)
    {
      if (n == 0 && ans[i] == '0')
        continue;

      if (n == 0 && ans[i] != '0')
        n = 1;
      printf("%c", ans[i]);
    }
    printf("\n");
  }
  return 0;
}