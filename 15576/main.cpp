#include <iostream>
#include <complex>
#include <vector>

using namespace std;

typedef complex<double> cpx;

int upper_2th(const int size) {
    int result = 1;

    while (result < size) {
        result *= 2;
    }

    return result;
}

vector<cpx> string_to_vec(const string &str, const int size) {
    vector<cpx> vec(size);

    for (int i = 0; i < str.size(); i++) {
        vec[i] = str[str.size() - i - 1] - '0';
    }

    return vec;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    cin >> a >> b;
    if (a == "0" || b == "0") {
        printf("0\n");
        return 0;
    }

    const double pi = acos(-1);
    const cpx j(0.0, 1.0);
    const int size = upper_2th(a.size() + b.size());
    const cpx w = exp(2.0 / size * pi * j);
    vector<cpx> f = string_to_vec(a, size);
    vector<cpx> g = string_to_vec(b, size);

    fft(f, w);
    fft(g, w);

    vector<cpx> h(size);
    for (int i = 0; i < size; i++) {
        h[i] = f[i] * g[i];
    }

    fft(h, conj(w));

    vector<int> result(size + 1);
    for (int i = 0; i < size; i++) {
        result[i] = round(h[i].real() / size);
    }

    for (int i = 0; i < size; i++) {
        if (result[i] >= 10) {
            result[i + 1] += result[i] / 10;
            result[i] %= 10;
        }
    }

    int i = size - 1;
    for (; i >= 0 && result[i] == 0; i--);
    for (; i >= 0; i--) {
        printf("%d", result[i]);
    }
    printf("\n");

    return 0;
}
