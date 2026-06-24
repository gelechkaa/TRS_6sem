#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Функция для вычисления производной dv/dt
double dv_dt(double t, double m) {
    return -4.0 / m * (t * cosh(t * t));
}

// Функция для вычисления производной dx/dt
double dx_dt(double t) {
    return t;
}

int main() {
    // Открытие файлов для записи
    ofstream X_1("X1_out.txt");
    ofstream V_1("V1_out.txt");

    ofstream Xh_1("X1_hout.txt");
    ofstream Vh_1("V1_hout.txt");

    double m = 1.67; // задано в условии
    vector<double> n = { 11, 101, 1001, 10001 }; // разное количество шагов

    // метод Эйлера
    for (int j = 0; j < n.size(); j++) {
        double x_n_1, x_n = x_n_1 = 0;
        double v_n_1, v_n = v_n_1 = 7;
        double h = 10. / n[j];

        Xh_1 << "h = " << h << endl;
        Vh_1 << "h = " << h << endl;

        for (int i = 0; i < n[j]; i++) {
            X_1 << i * h << " " << x_n << endl;
            V_1 << i * h << " " << v_n << endl;

            Xh_1 << i * h << " " << x_n << endl;
            Vh_1 << i * h << " " << v_n << endl;

            x_n = x_n_1 + h * dx_dt(v_n_1);
            v_n = v_n_1 + h * dv_dt(x_n_1, m);
            x_n_1 = x_n;
            v_n_1 = v_n;
        }
        Xh_1 << endl;
        Vh_1 << endl;
    }

    // Закрытие файлов
    X_1.close();
    V_1.close();
    Xh_1.close();
    Vh_1.close();

    return 0;
}
