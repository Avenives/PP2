#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cstring>
using namespace std;

class String
{
    public:
        String() :string_size(0), data(new char[0]) {};
        String(const char* new_text): string_size(new_text ? strlen(new_text) : throw std::invalid_argument("nullptr")), data(new char[string_size])
        {
            std::copy(new_text, new_text+string_size, data);
        }
        String(const String &original): string_size(original.string_size), data(new char[string_size])
        {
            std::copy(original.data, original.data+string_size, data);
        }

        ~String()
        {
           delete []data;
        }

        String& operator=(const char* newText)
        {
            if(newText==nullptr) throw std::invalid_argument("nullptr");
            std::copy(newText, newText+string_size, data);
            return *this;
        }

        String& operator=(const String &newText)
        {
            if(&newText!=this)
            {
                if(newText.data==nullptr) throw std::invalid_argument("nullptr");
                std::copy(newText.data, newText.data+string_size, data);

            }
            return *this;
        }

        size_t size() {return string_size;}
        const char* text() {return data;}

        String& operator+=(const char* text2Append)
        {
            char *temp = new char[string_size+strlen(text2Append)];
            int i=0;
            while(i<string_size)
            {
                temp[i]=data[i];
                ++i;
            }
            int j=0;
            while(j<strlen(text2Append))
            {
                temp[i+j]=text2Append[j];
                ++j;
            }
            data = temp;
            string_size+=strlen(text2Append);

            return *this;
        }

        char* operator+(const char* text2Append)
        {
            char *temp = new char[string_size+strlen(text2Append)];
            int i=0;
            while(i<string_size)
            {
                temp[i]=data[i];
                ++i;
            }
            int j=0;
            while(j<strlen(text2Append))
            {
                temp[i+j]=text2Append[j];
                ++j;
            }

            return temp;
        }

    friend std::istream& operator>>(std::istream& is, String& str)
    {
        char temp[256];
        cin >> temp;
        delete[] str.data;
        str.string_size=strlen(temp);
        str.data = new char[str.string_size];
        for(int i=0;i<str.string_size;++i)
        {
            str.data[i]=temp[i];
        }

        return is;
    }

    private:
        size_t string_size;
        char *data;
};

std::ostream& operator<<(std::ostream& os, String& str)
{
    cout << str.text();
    return os;
}

int main()
{
    String A;
    String B("BBB");
    char *pusty=nullptr;
    try
    {
        String C(pusty);
    }
    catch(std::invalid_argument &e)
    {
        cout << "wyjątek złapany: " << e.what() << "\n";
    }

    String s1("strings1"), s2;
    A=s2=s1;
    String C=A;
    s2=s2;

    String X;

    cout << "podaj tekst: " << "\n";
    char Z[16] = "dolaczony tekst";
    cin >> X;
    cout << "X+Z= " << (X+Z);
    X+=Z;
    cout << "\nX= " << X;
}
