#include <fstream>
#include <cstdlib>
#include <iostream>
#include <iomanip>      

using namespace std;

class file
{
	    string data; 
        ifstream inFile;
        int letters = 0;
        int t[26];
        int sum = 0;
        
        
        public:
                file();
                ~file();
                void loop(); 
                void howManyLetters();
                void frequency();
};


file::file()
{
        inFile.open("tekst.txt");
        if (!inFile.good())
        {
                cerr << "Blad - pliku nie da sie otworzyc!\n";
                exit(1);
        }
}

file::~file()
{
        inFile.close();
}

void file::loop()
{
        while (!inFile.eof())
        {
                inFile >> data;
        
        for(int i=0; i<data.length() - 1; i++){
			if(data[i] == data[i+1]){
				letters++;
				break;
		}
	}
		for(int j=0; j<data.length(); j++){
			t[data[j] - 'A']++;
		}
			sum += data.length();
	}

		
		for(int i=0; i<26; i++){
			cout << char('A' + i) << ": " << t[i];
			cout << " (" << fixed << setprecision(2) << 100 * ((double)t[i]/(double)sum) << " %)\n\n";
		}
	
	cout << "Ilosc takich samych kolejnych liter(73.1): " << letters << endl;
}

int main()
{
        file f;
        f.loop();
        return 0;
}
