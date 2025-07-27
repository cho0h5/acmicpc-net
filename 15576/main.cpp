#include <iostream>
#include <complex>

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
        vec[i + (size - str.size())] = str[i] - '0';
    }

    return vec;
}

void fft(vector<cpx> &f, const cpx w) {
    if (f.size() == 1) {
        return;
    }

    vector<cpx> feven(f.size());
    vector<cpx> fodd(f.size());
    for (int i = 0; i < f.size / 2(); i++) {
        feven[i] = f[i + 1];
        fodd[i] = f[i];
    }

    fft(feven, w * w);
    fft(fodd, w * w);

    for (int i = 0; i < f.size() / 2; i++) {
        f[i] = feven[i] + fodd[i] * w;
        f[i + f.size() / 2] = feven[i] - fodd[i] * w;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    cin >> a >> b;

    const int size = upper_2th(max(a.size(), b.size()));
    const int w = cos
    vector<cpx> f = string_to_vec(a, size);
    vector<cpx> g = string_to_vec(b, size);

    fft(f);
    fft(g);

    vector<cpx> h(size);
    for (int i = 0; i < size; i++) {
        h[i] = f[i] * g[i];
    }

    fft(h);

    return 0;
}
