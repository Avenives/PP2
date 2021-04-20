#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class NotUnderstandableFile
{
    public:
        /**
         * \brief   Constructor
         *
         * \param[in]     path  accepts path to a file in form of a string
         *
         * \return        does not return anything, it's a constructor
         */
        NotUnderstandableFile(string path) :filepath(path)
        {
            file.open(filepath);
            if(file.is_open()) cout << "otwarto plik: " << filepath << endl;
            else cout << "blad otwierania pliku: " << filepath << endl;
        }

         /**
         * \brief   Destructor
         */
        ~NotUnderstandableFile()
        {
            file.close();
            if(!file.is_open()) cout << "poprawnie zamkniety plik: " << filepath << endl;
            else cout << "blad przy zamykaniu pliku: " << filepath << endl;
        }

         /**
         * \brief   operator= makes a file a copy of another file
         *
         * \param[in]     NotUnderstandableFile& primary
         *                accepts NotUnderstandableFile& where data will be copied from
         *
         * \return        returns reference to a new copy
         */
        NotUnderstandableFile& operator=(const NotUnderstandableFile& primary)
        {
            if(&primary==this) return *this;
            ifstream primary_read(primary.filepath);
            ofstream output(filepath);
            string line;
            while(getline(primary_read,line))
            {
                 output << line << endl;
            }
            output.close();
            primary_read.close();

            return *this;
        }

        /**
         * \brief   operator+= appends one file to the end of another file
         *
         * \param[in]     NotUnderstandableFile& other
         *                accepts NotUnderstandableFile& - file that will be appended to the other file
         *
         * \return        returns reference to the file that data has been appended to.
         */
        NotUnderstandableFile& operator+=(NotUnderstandableFile& other)
        {
            ofstream appending(filepath, ios_base::app);
            string line;
            while(getline(other.file,line))
            {
                appending << line << endl;
            }
            appending.close();

            return *this;
        }

        /**
         * \brief   operator>> returns one next word in a file
         *
         * \param[in]     &word - string where a word will be put into.
         *
         * \return      returns reference to the file.
         */
        NotUnderstandableFile& operator>>(string &word)
        {
            file >> word;
            return *this;
        }

        /**
         * \brief   operator<< appends one string to the end of another file
         *
         * \param[in]     line - string that will be appended
         *
         * \return        returns reference to file that string has been appended to.
         */
        NotUnderstandableFile& operator<<(string line)
        {
            ofstream appending(filepath, ios_base::app);
            appending << line << endl;
            return *this;
        }

         /**
         * \brief   operator>> counts lines in a file.
         *
         * \param[in]     &number - int - where information will be put into.
         *
         * \return        returns reference to the file.
         */
        NotUnderstandableFile& operator>>(int &counter)
        {
            counter=count_lines();
            return *this;
        }

         /**
         * \brief   operator<< makes sure that number of lines in a file is at least equal to a given number.
         *
         * \param[in]     &number - int - number of lines.
         *
         * \return        returns reference to the file.
         */
        NotUnderstandableFile& operator<<(int number)
        {
            int n=count_lines();
            if(n<=number)
            {
                number-=n;
                string a="";
                while(number--)
                {
                    *this << a;
                }
            }
            return *this;
        }

        /**
         * \brief   operator& returns filepath to a file as a string
         *
         * \return      returns reference to the file.
         */
        string operator&()
        {
           return filepath;
        }

        /**
         * \brief   operator== checks if data in one file is identical to data in other file.
         *
         * \param[in]     NotUnderstandableFile& other - second file to compare.
         *
         * \return        returns bool.
         */
        bool operator==(NotUnderstandableFile& other)
        {
            ifstream first(filepath);
            ifstream second(other.filepath);
            string line1, line2;
            bool same=true;
            while(first >> line1)
            {
                second >> line2;
                if(line1!=line2)
                {
                    same=false;
                    break;
                }
            }
            first.close();
            second.close();
            return same;
        }

    private:
        const string filepath;
        fstream file;

        int count_lines()
        {
            ifstream input(filepath);
            int counter=0;
            string line;
            while(getline(input,line))
            {
                ++counter;
            }
            counter++;
            input.close();
            return counter;
        }

};


int main()
{
    NotUnderstandableFile A("tekst1.txt");
    NotUnderstandableFile B("tekst2.txt");
    NotUnderstandableFile C("tekst3.txt");
    NotUnderstandableFile emptyfile("emptyfile.txt");

    A=B=C;
    if(A==B) cout << "A==B\n";
    else cout << "A!=B\n";

    A << "manualnie dodana linia";
    if(A==B) cout << "A==B\n";
    else cout << "A!=B\n";

    A << 150;
    int n;
    A >> n;
    cout << "ilosc linii w pliku " << &A << " " << n << endl;
    A+=C;
    string a;
    A >> a;
    cout << a << endl;
}
