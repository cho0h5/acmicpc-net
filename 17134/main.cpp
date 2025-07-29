#include <iostream>
#include <complex>
#include <vector>

using namespace std;

typedef complex<double> cpx;

const double pi = acos(-1);
const cpx j(0.0, 1.0);

int maximum = 1000000;
int n;
vector<int> inputs;
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

void init_seive(const int thresh) {
    seive[0] = true;
    seive[1] = true;
    for (long long i = 0; i < thresh; i++) {
        if (seive[i]) continue;

        for (long long j = i * i; j < thresh; j += i) {
            seive[j] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Input
    cin >> n;
    inputs.reserve(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        inputs.push_back(x);
        maximum = max(maximum, x);
    }

    int size = upper_2th(maximum * 2);
    init_seive(1000000);
    // Set f and g
    vector<cpx> f(size);
    vector<cpx> g(size);
    for (int i = 0; i < 1000000; i++) {
        if (seive[i]) continue;

        if (i > 2) f[i] = 1;
        if (i * 2 < 1000000) g[i * 2] = 1;
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
    // Print results
    for (auto x: inputs) {
        printf("%d\n", (int)round(h[x].real()));
    }

    // Debug
    printf("--------\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", (int)round(h[i].real()));
    }
    printf("\n");

    return 0;
}
