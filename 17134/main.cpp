#include <iostream>
#include <complex>
#include <vector>

using namespace std;

typedef complex<double> cpx;

const double pi = acos(-1);
const cpx j(0.0, 1.0);

bool seive[1000000];

int upper_2th(const int size) {
    int result = 1;

    while (result < size) {
        result *= 2;
    }

    return result;
}

void fft(vector<cpx> &f, const cpx w) {
    if (f.size() == 1) {
        return;
    }

    vector<cpx> feven(f.size() / 2);
    vector<cpx> fodd(f.size() / 2);
    for (int i = 0; i < f.size() / 2; i++) {
        feven[i] = f[i * 2];
        fodd[i] = f[i * 2 + 1];
    }

    fft(feven, w * w);
    fft(fodd, w * w);

    cpx wi(1, 0);
    for (int i = 0; i < f.size() / 2; i++) {
        f[i] = feven[i] + fodd[i] * wi;
        f[i + f.size() / 2] = feven[i] - fodd[i] * wi;
        wi *= w;
    }
}

void init_seive() {
    seive[0] = true;
    seive[1] = true;
    for (int i = 0; i < 1000000; i++) {
        if (seive[i]) continue;

        for (int j = i * 2; j < 1000000; j += i) {
            seive[j] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init_seive();

    // Set f and g
    const int size = upper_2th(2000000);
    vector<cpx> f(size);
    vector<cpx> g(size);
    for (int i = 0; i < 1000000; i++) {
        if (seive[i]) continue;

        if (i > 2) f[i] = 1;
        g[i * 2] = 1;
    }

    // FFT
    const cpx w = exp(2.0 / size * pi * j);
    fft(f, w);
    fft(g, w);

    vector<cpx> h(size);
    for (int i = 0; i < size; i++) {
        h[i] = f[i] * g[i];
    }

    fft(h, conj(w));
    for (int i = 0; i < size; i++) {
        h[i] /= cpx(size, 0);
    }

    // Input
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;

        printf("%d\n", (int)round(h[x].real()));
    }

    return 0;
}
