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

    vector<cpx> feven(f.size() / 2);
    vector<cpx> fodd(f.size() / 2);
    for (int i = 0; i < f.size() / 2; i++) {
        feven[i] = f[i * 2 + 1];
        fodd[i] = f[i * 2];
    }

    fft(feven, w * w);
    fft(fodd, w * w);

    for (int i = 0; i < f.size() / 2; i++) {
        f[i] = feven[i] + fodd[i] * w;
        f[i + f.size() / 2] = feven[i] - fodd[i] * w;
    }
}

void print_cpxs(const vector<cpx> f) {
    for (int i = 0; i < f.size(); i++) {
        printf("%d ", (int)round(f[i].real()));
    }
    printf("\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    cin >> a >> b;

    const double pi = acos(-1);
    const cpx j(0.0, 1.0);
    const int size = upper_2th(a.size() + b.size());
    const cpx w = exp(2.0 / size * pi * j);
    printf("w: %f + %fi\n", w.real(), w.imag());
    vector<cpx> f = string_to_vec(a, size);
    vector<cpx> g = string_to_vec(b, size);

    printf("f : ");
    print_cpxs(f);
    printf("g : ");
    print_cpxs(g);
    printf("\n");

    fft(f, w);
    fft(g, w);

    printf("f': ");
    print_cpxs(f);
    printf("g': ");
    print_cpxs(g);
    printf("\n");

    vector<cpx> h(size);
    for (int i = 0; i < size; i++) {
        h[i] = f[i] * g[i];
    }

    printf("h': ");
    print_cpxs(h);

    fft(h, conj(w));

    for (int i = 0; i < size; i++) {
        h[i] /= size;
    }

    printf("h : ");
    print_cpxs(h);

    return 0;
}
