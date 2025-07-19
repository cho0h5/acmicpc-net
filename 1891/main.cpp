#include <iostream>

using namespace std;
typedef long long ll;

void decode(const ll d, const string num, ll *x, ll *y) {
    *x = 1;
    *y = 1;

    ll mul = 1;
    for (int i = d - 1; i >= 0; i--) {
        ll n = num[i] - '0';

        switch (n) {
            case 1:
                *x += 1 * mul;
                *y += 1 * mul;
                break;

            case 2:
                *y += 1 * mul;
                break;

            case 3:
                break;

            case 4:
                *x += 1 * mul;
                break;
        }

        mul *= 2;
    }
}

void encode(const ll d, ll x, ll y) {
    // printf("(%lld, %lld)\n", x, y);

    ll mul = 1;
    for (int i = 0; i < d - 1; i++) {
        mul *= 2;
    }

    ll result = 0;
    for (int i = 0; i < d; i++) {
        // printf("mul: %lld, (%lld, %lld)\n", mul, x, y);
        if (x > mul && y > mul) {
            printf("1");
            x -= mul;
            y -= mul;
        } else if (x > mul) {
            printf("4");
            x -= mul;
        } else if (y > mul) {
            printf("2");
            y -= mul;
        } else {
            printf("3");
        }

        mul /= 2;
    }
    printf("\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll d;
    string num;
    ll dx, dy;
    cin >> d >> num;
    cin >> dx >> dy;

    ll x, y;
    decode(d, num, &x, &y);

    x += dx;
    y += dy;

    ll boundary = 1;
    for (int i = 0; i < d; i++) {
        boundary *= 2;
    }

    if (x > boundary || y > boundary || x <= 0 || y <= 0) {
        printf("-1\n");
        return 0;
    }

    encode(d, x, y);
}
