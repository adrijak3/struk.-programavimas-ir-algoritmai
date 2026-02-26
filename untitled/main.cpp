#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double GBP_Bendras = 0.8729;
    double GBP_Pirkti = 0.8600;
    double GBP_Parduoti = 0.9220;
    double USD_Bendras = 1.1793;
    double USD_Pirkti = 1.1460;
    double USD_Parduoti = 1.2340;
    double INR_Bendras = 104.6918;
    double INR_Pirkti = 101.3862;
    double INR_Parduoti = 107.8546;
    int pasirinkimas;
    string valiuta;
    double kiekis;
    cout << "Pasirinkite veiksma: " << endl;
    cout << "1 - palyginimas" << endl;
    cout << "2 - pirkimas " << endl;
    cout << "3 - pardavimas" << endl;
    cin >> pasirinkimas;
    cout << "valiuta - GBP, USD, INR " << endl;
    cin >> valiuta;
    cout << fixed << setprecision(2) << endl;

    switch (pasirinkimas)
{ case 1:  // palyginame kiekvieną valiutą
         if (valiuta == "GBP")
         {
             cout << "1 EUR yra " << GBP_Bendras << " GBP"<< endl;
             cout << "1 GBP yra " << 1 / GBP_Bendras << " EUR"<< endl;
         }
         else if (valiuta == "USD")
          {
             cout << "1 EUR yra " << USD_Bendras << " USD"<< endl;
             cout << "1 USD yra " << 1 / USD_Bendras << " EUR"<< endl;
          }
         else if (valiuta == "INR")
          {
             cout << "1 EUR yra " << INR_Bendras << " INR"<< endl;
              cout << "1 INR yra " << 1 / INR_Bendras << " EUR"<< endl;
         }
          else  {cout << "Neteisinga valiuta";}
            break;
        case 2:  // pirkimas valiutos
            cout << "Euru kiekis - ";
            cin >> kiekis;

            if (valiuta == "GBP")
                cout << "Tai yra lygu" << " " << kiekis * GBP_Pirkti << " GBP"<< endl;
            else if (valiuta == "USD")
                cout << "Tai yra lygu" << " " << kiekis * USD_Pirkti << " USD"<< endl;
            else if (valiuta == "INR")
                cout << "Tai yra lygu" << " " << kiekis * INR_Pirkti << " INR"<< endl;
            else
                 {cout << "Neteisinga valiuta";}
            break;

        case 3:  // valiutos pardavimas
            cout << "Kiekis valiutos - ";
            cin >> kiekis;

            if (valiuta == "GBP")
                cout << "Tai yra lygu" << " " << kiekis * GBP_Parduoti << " EUR"<< endl;
            else if (valiuta == "USD")
                cout << "Tai yra lygu" << " " << kiekis * USD_Parduoti << " EUR"<< endl;
            else if (valiuta == "INR")
                cout << "Tai yra lygu" << " " << kiekis * INR_Parduoti << " EUR"<< endl;
            else
                 {cout << "Neteisinga valiuta";}
            break;

        default:
            cout << "Netinkamas ar neteisingai įvestas pasirinkimas" << endl;
}
    return 0;
}