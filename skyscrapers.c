#include<stdio.h>


int checksol(int n, int q[n][n], int a[4][n], int l) {
  ;
  int rev_sto = 0, flag = 0, fwd = 0, rev = 1, sto = 0, j = 0, i = 0;
  char h;
  for (; i < n;) {
    rev_sto = 0;
    sto = 0;
    j = 0;
    fwd = 0;
    rev = 1;
    for (; j <= l; ++j)
      if (sto != n) {
        if (q[j][i] > sto) {
          ++fwd;
          sto = q[j][i];
        }
      }
    else {
      {
        if (q[j][i] < q[j - 1][i]) {
          if (q[j - 1][i] == n)
            rev_sto = q[j][i];
          ++rev;
        }
        if (q[j][i] > rev_sto) {
          rev = 2;
          rev_sto = q[j][i];
        }
      }
    }
    ++i;
    if ((l < n - 1 && fwd > a[0][i - 1]) || (l == n - 1 && !(fwd == a[0][i - 1] && rev == a[1][i - 1])))
      return -1;
  }

  return flag;

}

int checkro(int n, int q[n][n], int a[4][n], int r) {
  char h;
  int rev_sto = 0, flag = -1, fwd = 0, rev = 1, sto = 0, j = 0, i = 0;
  for (; j < n; ++j)
    if (sto != n) {
      if (q[r][j] > sto) {
        ++fwd;
        sto = q[r][j];
      }
    }
  else {
    if (q[r][j] < q[r][j - 1]) {
      if (q[r][j - 1] == n)
        rev_sto = q[r][j];
      ++rev;
    }
    if (q[r][j] > rev_sto) {
      rev = 2;
      rev_sto = q[r][j];
    }

  }

  if (a[2][r] == fwd && a[3][r] == rev)
    return 1;
  else
    return -1;
}

int check(int n, int i, int q[][n], int x, int r, int a[4][n]) {
  int flag = -1;
  int j = 0;
  char h;

  if (x > n)
    flag = -2;

  if (flag == -1)
    for (; j < i && x <= n; ++j) {
      if (x == q[r][j])
      {
        flag = x;
        flag = check(n, i, q, x + 1, r, a);
        break;
      }
    }

  for (j = 0; flag == -1 && j < r && x <= n; ++j) {
    if (x == q[j][i])
    {
      flag = 90;
      flag = check(n, i, q, x + 1, r, a);
      break;
    }
  }

  if (flag == -2)
    return 'A';
  else if (flag != -1)
    return flag;
  else
    return x;

}

int gen(int n, int a[4][n]) {
  int z = 1;
  int q[n][n];
  char h;
  int j = 0, po = 0, i = 0, fnl = 0;

  for (; i < n && i >= 0;) {
    for (; j < n && j >= 0;) {
      q[i][j] = check(n, j, q, z, i, a);

      if (q[i][j] == 'A') {
        --j;

        if (q[i][j] == n)
          if (j > 0)
            --j;
          else
            j = -9;
        z = q[i][j] + 1;
      } else if (q[i][j] >= 0 && q[i][j] <= n) {
        z = 1;
        ++j;
      }

    }

    z = checkro(n, q, a, i);
    fnl = checksol(n, q, a, i);
    if (z == 1 && fnl != -1 && j != -9) {
      ++i;
      z = 1;
      j = 0;
    } else {
      for (fnl = 0; fnl < n && q[i][fnl] <= n; ++fnl);
      if (fnl != n)
        if (i > 0)
          --i;
        else
          return 0;
      for (fnl = n - 1; q[i][fnl] == n; --fnl);
      z = q[i][fnl] + 1;
      j = fnl;
    }

    if (q[0][1] == 3 && q[0][2] == 4 && q[0][3] == 5 && q[0][4] == 2 && q[1][0] >= 5 && q[1][1] == 1 && q[1][2] == 3 && q[1][3] == 2 && q[2][0] == 4)
      scanf("%c", & h);
  }


  for (int x1 = 0; x1 < n; ++x1) {
    for (int y1 = 0; y1 < n; ++y1)
      printf("%d\t", q[x1][y1]);
    printf("\n");
  }

}

int main() {

  int a[4][6] = {
    {
      3,
      2,
      3,
      2,
      2,
      1
    },
    {
      2,
      3,
      1,
      3,
      5,
      2
    },
    {
      5,
      2,
      2,
      3,
      1,
      3
    },
    {
      1,
      2,
      3,
      3,
      5,
      2
    }
  };

  gen(6, a);
}
