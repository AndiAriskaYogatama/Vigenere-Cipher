#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Vigenere
{
public:
  string key;

  Vigenere(string key)
  {
    for(int i = 0; i < key.size(); ++i)
    {
      if(key[i] >= 'A' && key[i] <= 'Z')
        this->key += key[i];
      else if(key[i] >= 'a' && key[i] <= 'z')
        this->key += key[i] + 'A' - 'a';
    }
  }

  string encrypt(string text)
  {
    string out;

    for(int i = 0, j = 0; i < text.length(); ++i)
    {
      char c = text[i];

      if(c >= 'a' && c <= 'z')
        c += 'A' - 'a';
      else if(c < 'A' || c > 'Z')
        continue;

      out += (c + key[j] - 2*'A') % 26 + 'A';
      j = (j + 1) % key.length();
    }

    return out;
  }

  string decrypt(string text)
  {
    string out;

    for(int i = 0, j = 0; i < text.length(); ++i)
    {
      char c = text[i];

      if(c >= 'a' && c <= 'z')
        c += 'A' - 'a';
      else if(c < 'A' || c > 'Z')
        continue;

      out += (c - key[j] + 26) % 26 + 'A';
      j = (j + 1) % key.length();
    }

    return out;
  }
};

int main()
{

  string options, plaintext, ciphertext, keyword;
  cout<<"VIGENERE CIPHER"<<endl<<endl;
  cout<<"0 |A B C D E F G H I J K L M N O P Q R S T U V W X Y Z"<<endl;
  cout<<"--+---------------------------------------------------"<<endl;
  cout<<"A |A B C D E F G H I J K L M N O P Q R S T U V W X Y Z"<<endl;
  cout<<"B |B C D E F G H I J K L M N O P Q R S T U V W X Y Z A"<<endl;
  cout<<"C |C D E F G H I J K L M N O P Q R S T U V W X Y Z A B"<<endl;
  cout<<"D |D E F G H I J K L M N O P Q R S T U V W X Y Z A B C"<<endl;
  cout<<"E |E F G H I J K L M N O P Q R S T U V W X Y Z A B C D"<<endl;
  cout<<"F |F G H I J K L M N O P Q R S T U V W X Y Z A B C D E"<<endl;
  cout<<"G |G H I J K L M N O P Q R S T U V W X Y Z A B C D E F"<<endl;
  cout<<"H |H I J K L M N O P Q R S T U V W X Y Z A B C D E F G"<<endl;
  cout<<"I |I J K L M N O P Q R S T U V W X Y Z A B C D E F G H"<<endl;
  cout<<"J |J K L M N O P Q R S T U V W X Y Z A B C D E F G H I"<<endl;
  cout<<"K |K L M N O P Q R S T U V W X Y Z A B C D E F G H I J"<<endl;
  cout<<"L |L M N O P Q R S T U V W X Y Z A B C D E F G H I J K"<<endl;
  cout<<"M |M N O P Q R S T U V W X Y Z A B C D E F G H I J K L"<<endl;
  cout<<"N |N O P Q R S T U V W X Y Z A B C D E F G H I J K L M"<<endl;
  cout<<"O |O P Q R S T U V W X Y Z A B C D E F G H I J K L M N"<<endl;
  cout<<"P |P Q R S T U V W X Y Z A B C D E F G H I J K L M N O"<<endl;
  cout<<"Q |Q R S T U V W X Y Z A B C D E F G H I J K L M N O P"<<endl;
  cout<<"R |R S T U V W X Y Z A B C D E F G H I J K L M N O P Q"<<endl;
  cout<<"S |S T U V W X Y Z A B C D E F G H I J K L M N O P Q R"<<endl;
  cout<<"T |T U V W X Y Z A B C D E F G H I J K L M N O P Q R S"<<endl;
  cout<<"U |U V W X Y Z A B C D E F G H I J K L M N O P Q R S T"<<endl;
  cout<<"V |V W X Y Z A B C D E F G H I J K L M N O P Q R S T U"<<endl;
  cout<<"W |W X Y Z A B C D E F G H I J K L M N O P Q R S T U V"<<endl;
  cout<<"X |X Y Z A B C D E F G H I J K L M N O P Q R S T U V W"<<endl;
  cout<<"Y |Y Z A B C D E F G H I J K L M N O P Q R S T U V W X"<<endl;
  cout<<"Z |Z A B C D E F G H I J K L M N O P Q R S T U V W X Y"<<endl;
  cout<<endl<<"Apa yang ingin anda lakukan? en/de"<<endl;
  cin>>options;
  if(options == "en")
  {
      cout<<endl<<"Enkripsi"<<endl;
      cout<<endl<<"Masukan plaintext: ";
      cin>>plaintext;
      cout<<endl<< "Masukan key anda : ";
      cin>>keyword;
  }

  else if(options == "de")
  {
      cout<<endl<<"Dekripsi"<<endl;
      cout<<endl<<"Masukan ciphertext: ";
      cin>>ciphertext;
      cout<<endl<< "Masukan key anda  : ";
      cin>>keyword;
  }

  else
  {
      cout<<"Maaf, input anda salah!!!"<<endl;
      return 0;
  }


  Vigenere cipher(keyword);
  string encrypted = cipher.encrypt(plaintext);
  string decrypted = cipher.decrypt(ciphertext);
  if(options == "en")
  {
      cout<<endl<< "Hasil  Enkripsi  : " << encrypted << endl;
  }
  else if(options == "de")
  {
      cout<<endl<< "Hasil  Dekripsi   : " << decrypted << endl;
  }
  else
  {
      cout<<"Maaf, input anda salah!!!"<<endl;
      return 0;
  }

}
