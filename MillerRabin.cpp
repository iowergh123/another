#include <bits/stdc++.h>
using namespace std;
int N;
int prime[3] = {2,7,61};

int PowMod(int a, int b, int n) {
   int res = 1;
   a %= n;    //Nhớ phải lấy a mod n;
   while (b > 0) {
    if (b % 2 != 0) res = (__int128)res*a%n;
    a = (__int128)a*a%n;
    b /= 2;
   }
   return res;
}

bool check(int N) {
   if (N < 2) return false; // Phải có dòng này để né 1 và 0;
   if (N == 2 || N == 3) return true;
   if (N % 2 == 0) return false;

   int d = N-1;  // các biến a,d,s buộc phải khai báo trong hàm
   int s = 0;
   while (d % 2 == 0) {   // PHẢI LÀ D % 2 == 0 !!
     d /= 2;
     s++;
   }

   for (int &a : prime) {
     if (N == a) return true; // Nếu bằng phải return true ko sẽ lặp vô hạn
     if (N < a) break; // Với các cơ số lớn hơn N thì không cần xét nữa
     int x = PowMod(a,d,N);
     if (x == 1 || x == N-1) continue; // Hoặc
     bool pass = false;

     for (int i = 1; i <= s-1; i++) {
        x = (__int128)x*x%N;
        if (x == N-1) {
            pass = true;
            break;
        }
     }
     if (!pass) return false;
   }

  return true;
}

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 freopen("INPUT.INP","r",stdin);
 freopen("OUTPUT.OUT","w",stdout);
 cin >> N;
 cout << check(N);
}
