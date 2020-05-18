// Author: Le Yen Thanh

struct point{ double x, y; };
inline point operator+(point a, point b)
{ a.x += b.x; a.y += b.y; return a; }
inline point operator-(point a, point b)
{ a.x -= b.x; a.y -= b.y; return a; }
inline point operator*(point a, point b)
{ point c; c.x = a.x * b.x - a.y * b.y; c.y = a.x * b.y + a.y * b.x; return c; }
inline point newpoint(double r, double t)
{ point c; c.x = r * cos(t); c.y = r * sin(t); return c; }

void fft(unsigned int n, double theta, point a[]) {
  unsigned int m, len, i, j;
  register point t, w;
  for (m = n; m > 1; m >>= 1) {
    len = m / 2;
    for(int d=0; d<len; ++d){
      w = newpoint(1, theta * d);
      for (i = d; i < n; i += m) {
        j = i + len; t = a[i] - a[j];
        a[i] = a[i] + a[j]; a[j] = w * t;
      }
    } theta *= 2;
  } i = 0;
  for(j = 1; j < n; ++j){
    for (int k = n / 2; k > (i ^= k); k >>= 1);
    if (j < i) swap(a[i], a[j]);
  }
}

const int M = 131072;
point a[M], b[M], c[M];

//FFT
fft(M, 2.0 * pi / M, a);
fft(M, 2.0 * pi / M, b);
REP(i, M) c[i] = a[i] * b[i];
fft(M, -2.0 * pi / M, c) c[i].x = c[i].x / M;
