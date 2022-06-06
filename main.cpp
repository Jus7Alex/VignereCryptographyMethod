#include<iostream>
#include<string>
using namespace std;

class Vigenere
{
    public:
        string key;

        Vigenere(string key)
        {
            for (int i = 0; i < key.size(); ++i)
            {
                if (key[i] >= 'A' && key[i] <= 'Z')
                    this->key += key[i];
                else if (key[i] >= 'a' && key[i] <= 'z')
                    this->key += key[i] + 'A' - 'a';
            }
        }

        string cypher(string text)
        {
            string out;

            for (int i = 0, j = 0; i < text.length(); ++i)
            {
                char c = text[i];

                if (c >= 'a' && c <= 'z')
                    c += 'A' - 'a';
                else if (c < 'A' || c > 'Z')
                    continue;

                out += (c + key[j] - 2 * 'A') % 26 + 'A';
                j = (j + 1) % key.length();
            }

            return out;
        }
};

int main()
{
    //Apelam clasa Vigenere ce creeaza un obiect numit mesaj
    Vigenere mesaj("CRIPTARE");

    string original = "EXISTA O NISA DE SECURITATE IN COMUNICAREA WIRELESS";
    string mesajFinal = mesaj.cypher(original);

    cout <<"Mesajul original: "<< original << endl;
    cout << "Mesaj final: " << mesajFinal << endl;

}
