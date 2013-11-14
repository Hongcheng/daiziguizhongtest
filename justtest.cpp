#include <iostream>
using namespace std;

template<int N, int c>
class get_wine_amount {
public:
    float operator()(int n) {
        float ret = 0;
        int x, y;

        for (x = 1; ;x++) {
            if (((x + 1) * x)/2 >= n)
                break;
        }

        y = n - ((x - 1) * x)/2;
        cout << x << " " << y;
        ret = get_unlimited_wine_amount(x, y);

        return ret > c ? c : ret;
    }
private:
    int n;
    float get_unlimited_wine_amount(int x, int y) {
        if (x == 1 && y == 1) {
            return N;
        }

        float ret = 0;
        if (y == 1 || y == x) {
            ret = 1.0 * (get_unlimited_wine_amount(x-1, 1) -c ) /2;
            return ret > 0 ? ret : 0;
        }

        float left = get_unlimited_wine_amount(x-1, y-1) - c;
        left = left > 0 ? left : 0;
        float right = get_unlimited_wine_amount(x-1, y) - c;
        right = right > 0 ? right : 0;

        ret = (left + right) / 2;
        return ret > 0 ? ret : 0;
    }
};

int main() {
    auto get = get_wine_amount<20, 2>();

    for (int i=1; i<20; i++) {
        cout << i << " = " << get(i) << endl;
    }

    return 0;
}