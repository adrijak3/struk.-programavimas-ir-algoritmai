#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void linija()
{
    cout << "------------\n";
}

int main()
{
    string vardai[100];
    int pazymiai[100][10];
    int pazymiuKiekis[100];
    int mokiniuKiekis = 0;
    char pasirinkimas;

    while (true) {
        linija();
        cout << "meniu\n";
        cout << "1. Prideti mokini ir jo pazymius\n";
        cout << "2. Perziureti visus mokinius ir pazymius\n";
        cout << "3. Perziureti konkretaus mokinio pazymius\n";
        cout << "4. Atnaujinti mokinio pazymi\n";
        cout << "5. Pasalinti mokini\n";
        cout << "6. Iseiti\n";
        linija();
        cout << "Pasirinkite veiksma\n> ";

        cin >> pasirinkimas;


        switch (pasirinkimas) {
            case '1':
                if (mokiniuKiekis>=100) {
                    linija();
                    cout <<"Siuo metu sistemoje yra per daug mokiniu.";
                    linija();
                    break;
                }
                cout <<"Iveskite mokinio varda:\n> ";
                cin >> vardai[mokiniuKiekis];

                cout <<"Kiek pazymiu norite ivesti? \n> ";
                cin >> pazymiuKiekis[mokiniuKiekis];

                while (pazymiuKiekis[mokiniuKiekis] > 10 || pazymiuKiekis[mokiniuKiekis] < 1) {
                    linija();
                    cout << "Ivesta per daug arba per mazai pazymiu.\n";
                    linija();
                    cout << "Kiek pazymiu norite ivesti?\n> ";
                    cin >> pazymiuKiekis[mokiniuKiekis];
                }

                for (int i = 0; i < pazymiuKiekis[mokiniuKiekis]; i++) {
                    cout << "Pazymys " << i + 1 << ": ";
                    cin >> pazymiai[mokiniuKiekis][i];

                    while (pazymiai[mokiniuKiekis][i] < 1 || pazymiai[mokiniuKiekis][i] > 10) {
                        linija();
                        cout << "klaida. Iveskite pazymi nuo 1 iki 10.\n> ";
                        cin >> pazymiai[mokiniuKiekis][i];
                    }
                }
                linija();
                cout << "done\n";
                mokiniuKiekis++; //padidinam +1 nes idejom mokini
                break;

            case '2':
            {
                if (mokiniuKiekis == 0) {
                    linija();
                    cout << "Sistemoje nera jokiu mokiniu.\n";
                    break;
                }

                cout << "\nvisi mokiniai\n";

                for (int i = 0; i < mokiniuKiekis; i++) {
                    cout << i + 1 << ". " << vardai[i] << ": ";

                    for (int j = 0; j < pazymiuKiekis[i]; j++) { //pridedam viena
                        cout << pazymiai[i][j] << " ";
                    }

                    cout << endl;
                }
                break;
            }

            case '3':
            {
                if (mokiniuKiekis == 0) {
                    linija();
                    cout << "Sistemoje nera mokiniu.\n";
                    break;
                }

                cout << "\nSarasas\n";
                for (int i = 0; i < mokiniuKiekis; i++) {
                    cout << i + 1 << ". " << vardai[i] << endl; // vel +1 visual
                }

                int numeris;
                cout << "Iveskite mokinio numeri:\n> ";
                cin >> numeris;

                numeris = numeris - 1; // nes masyvas nuo 0

                if (numeris < 0 || numeris >= mokiniuKiekis) {
                    linija();
                    cout << "Tokio mokinio nera.\n";
                    break;
                }
                cout << "Mokinys: " << vardai[numeris] << endl;
                cout << "Pazymiai: ";

                for (int i = 0; i < pazymiuKiekis[numeris]; i++) {
                    cout << pazymiai[numeris][i] << " ";
                }

                cout << endl;
                break;
            }

            case '4':
            {
                if (mokiniuKiekis == 0) {
                    linija();
                    cout << "Sistemoje nera mokiniu.\n";
                    break;
                }

                cout << "\nSarasas\n";
                for (int i = 0; i < mokiniuKiekis; i++) {
                    cout << i + 1 << ". " << vardai[i] << endl; //plius vienas
                }

                int numeris;
                cout << "Iveskite mokinio numeri:\n> ";
                cin >> numeris;

                numeris = numeris - 1; // start over or sum

                if (numeris < 0 || numeris >= mokiniuKiekis) {
                    linija();
                    cout << "Tokio mokinio nera.\n";
                    break;
                }

                cout << "Mokinys: " << vardai[numeris] << endl;
                if (pazymiuKiekis[numeris] == 0) {
                    linija();
                    cout << "Sis mokinys neturi pazymiu.\n";
                    break;
                }

                // pazymiuai su numeriais
                for (int i = 0; i < pazymiuKiekis[numeris]; i++) {
                    cout << i + 1 << ". " << pazymiai[numeris][i] << endl;
                }

                int indeksas;
                cout << "Kuri pazymi norite keisti?\n> ";
                cin >> indeksas;

                indeksas = indeksas - 1; //resetttt

                if (indeksas < 0 || indeksas >= pazymiuKiekis[numeris]) {
                    linija();
                    cout << "Tokio pazymio nera.\n";
                    break;
                }

                int naujas;
                cout << "Iveskite nauja pazymi:\n> ";
                cin >> naujas;

                // kad teisingas pazymys
                if (naujas < 1 || naujas > 10) {
                    linija();
                    cout << "Blogas pazymys. Turi buti nuo 1 iki 10.\n";
                    break;
                }

                pazymiai[numeris][indeksas] = naujas;
                linija();
                cout << "Pazymys sekmingai atnaujintas.\n";
                break;
            }

            case '5':
            {
                if (mokiniuKiekis == 0) {
                    linija();
                    cout << "Sistemoje nera mokiniu.\n";
                    break;
                }

                cout << "\nSarasas\n";
                for (int i = 0; i < mokiniuKiekis; i++) {
                    cout << i + 1 << ". " << vardai[i] << endl;
                }

                int numeris;
                cout << "Kuri mokini norite pasalinti? mokinio numeris:\n> ";
                cin >> numeris;

                numeris = numeris - 1;

                if (numeris < 0 || numeris >= mokiniuKiekis) {
                    linija();
                    cout << "Tokio mokinio nera.\n";
                    break;
                }


                for (int i = numeris; i < mokiniuKiekis - 1; i++) {
                    vardai[i] = vardai[i + 1];
                    pazymiuKiekis[i] = pazymiuKiekis[i + 1];

                    for (int j = 0; j < 10; j++) {
                        pazymiai[i][j] = pazymiai[i + 1][j];
                    }
                }

                mokiniuKiekis--;
                linija();
                cout << "Mokinys sekmingai pasalintas.\n";
                break;
            }
            case '6':
                linija();
                cout << "baigta\n";
                linija();
                return 0;

            default:
                linija();
                cout << "klaida.\n";
                break;
        }
    }

    return 0;
}
