#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int main()
{
    string vardai[100];
    int pazymiai[100][10];
    int pazymiuKiekis[100];
    int mokiniuKiekis = 0;
    char pasirinkimas;

    while (true) {

        cout << "1. Prideti mokini ir jo pazymius\n";
        cout << "2. Perziureti visus mokinius ir pazymius\n";
        cout << "3. Perziureti konkretaus mokinio pazymius\n";
        cout << "4. Atnaujinti mokinio pazymi\n";
        cout << "5. Pasalinti mokini\n";
        cout << "6. Iseiti\n";
        cout << "Pasirinkite veiksma!:)\n> ";

        cin >> pasirinkimas;
        switch (pasirinkimas) {
            case '1':
                if (mokiniuKiekis>=100) {
                    cout <<"Siuo metu sistemoje yra per daug mokiniu.";
                    break;
                }
                cout <<"Iveskite mokinio varda:\n> ";
                cin >> vardai[mokiniuKiekis];

                cout <<"Kiek pazymiu norite ivesti? \n> ";
                cin >> pazymiuKiekis[mokiniuKiekis];

                while (pazymiuKiekis[mokiniuKiekis] > 10 || pazymiuKiekis[mokiniuKiekis] < 1) {
                    cout << "Ivesta per daug arba per mazai pazymiu.\n";
                    cout << "Kiek pazymiu norite ivesti?\n> ";
                    cin >> pazymiuKiekis[mokiniuKiekis];
                }

                for (int i = 0; i < pazymiuKiekis[mokiniuKiekis]; i++) {
                    cout << "Pazymys " << i + 1 << ": ";
                    cin >> pazymiai[mokiniuKiekis][i];
                    while (pazymiai[mokiniuKiekis][i] < 1 || pazymiai[mokiniuKiekis][i] > 10) {
                        cout << "klaida. Iveskite pazymi nuo 1 iki 10.\n> ";
                        cin >> pazymiai[mokiniuKiekis][i];
                    }
                }

                cout << "done\n";
            cout <<".................." << endl;
                mokiniuKiekis++; //padidinam +1 nes idejom mokini
                break;

            case '2':
            {
                if (mokiniuKiekis == 0) {

                    cout << "Nera jokiu mokiniu.\n";
                    cout <<".................." << endl;
                    break;
                }

                cout << "\nvisi mokiniai:\n";

                for (int i = 0; i < mokiniuKiekis; i++) {
                    cout << i + 1 << ". " << vardai[i] << ": ";

                    for (int j = 0; j < pazymiuKiekis[i]; j++) { //pridedam viena
                        cout << pazymiai[i][j] << " ";
                    }

                    cout << endl;
                    cout <<".................." << endl;
                }
                break;
            }

            case '3':
            {
                if (mokiniuKiekis == 0) {

                    cout << "Sistemoje nera mokiniu.\n";
                    cout <<".................." << endl;
                    break;
                }

                cout << "\nSarasas\n";
                for (int i = 0; i < mokiniuKiekis; i++) {
                    cout << i + 1 << ". " << vardai[i] << endl; // vel +1 kad graziau:)
                }

                int numeris;
                cout << "Iveskite mokinio numeri -\n> ";
                cin >> numeris;

                numeris = numeris - 1; // nes masyvas nuo 0 bet mes matom nuo vienetuko

                if (numeris < 0 || numeris >= mokiniuKiekis) {

                    cout << "Tokio mokinio nera :(\n";
                    cout <<".................." << endl;
                    break;
                }
                cout << "Mokinys - " << vardai[numeris] << endl;
                cout << "Pazymiai - ";

                for (int i = 0; i < pazymiuKiekis[numeris]; i++) {
                    cout << pazymiai[numeris][i] << " ";
                }
                cout << endl;
                break;
            }

            case '4':
            {
                if (mokiniuKiekis == 0) {

                    cout << "Sistemoje nera mokiniu.\n";
                    cout <<".................." << endl;
                    break;
                }

                cout << "\nSarasas\n";
                for (int i = 0; i < mokiniuKiekis; i++) {
                    cout << i + 1 << ". " << vardai[i] << endl;
                }

                int numeris;
                cout << "Iveskite mokinio numeri -\n> ";
                cin >> numeris;

                numeris = numeris - 1;

                if (numeris < 0 || numeris >= mokiniuKiekis) {

                    cout << "Tokio mokinio nera.\n";
                    cout <<".................." << endl;
                    break;
                }

                cout << "Mokinys: " << vardai[numeris] << endl;
                if (pazymiuKiekis[numeris] == 0) {

                    cout << "Sis mokinys neturi pazymiu.\n";
                    break;
                }

                // pazymiuai kad butu sunumeruoti
                for (int i = 0; i < pazymiuKiekis[numeris]; i++) {
                    cout << i + 1 << ". " << pazymiai[numeris][i] << endl;
                }

                int indeksas;
                cout << "Kuri pazymi norite keisti?\n> ";
                cin >> indeksas;

                indeksas = indeksas - 1; //resetttt pazymys kad panaikintu

                if (indeksas < 0 || indeksas >= pazymiuKiekis[numeris]) {

                    cout << "Tokio pazymio nera.\n";
                    cout <<".................." << endl;
                    break;
                }
                int naujas;
                cout << "Iveskite nauja pazymi:\n> ";
                cin >> naujas;

                // kad teisingas pazymys
                if (naujas < 1 || naujas > 10) {

                    cout << "Pazymys turi buti nuo 1 iki 10!\n";
                    break;
                }

                pazymiai[numeris][indeksas] = naujas;

                cout << "Pazymys sekmingai atnaujintas!:)\n";
                    cout <<".................." << endl;
                break;
            }
            case '5':
            {
                if (mokiniuKiekis == 0) {

                    cout << "Sistemoje nera mokiniu.\n";
                    cout <<".................." << endl;
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

                    cout << "Tokio mokinio nera.\n";
                    cout <<".................." << endl;
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

                cout << "Mokinys sekmingai pasalintas.\n";
                    cout <<".................." << endl;
                break;
            }
            case '6':

                cout << "baigta!\n";

                return 0;

            default:

                cout << "klaida :')\n";
                break;
        }
    }

    return 0;
}
