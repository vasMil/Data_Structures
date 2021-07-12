#include "myHeader.h"
#include "inputValues.h"

using namespace std;

class inputValues;

void transfer(string filename, vector<vector<inputValues> >& vec_m) {
	vector<inputValues> vec;
	char x, time[20] = "";                     //sto array pernao olo to timestamp (prosoxh sto mege8os, prepei na einai 1 parapano apo ta stoixeia pou 8a mpoune)
	string value;
	int d = -1, m = -1;                      //d=days && m=metrhsh oste na prospelaso ta stoixeia tou 2d vector
	bool fm = 0;                            //fm (flag_metrisis) == 1 oso epe3ergazomai akoma pliroforia gia thn metrhsh (isos na mporo na to paraleipso diathrontas mono to count)
	int count = 0;                         //count posa " pernane. Sta 4 prepei fm = 0.
	inputValues tempor;

	fstream arx;
	arx.open(filename.c_str(), ios::in);

	while (arx.is_open() && !arx.eof()) {
		arx.get(x);
		if (x == '{') {
			d++;
		}
		else if (x == '"' && fm == 0) {
			m++;
			fm = 1;
			count++;
			arx.read(time, sizeof(time) - 1);
		}
		else if (x == '"' && fm == 1) {
			count++;
		}
		if (count == 4) {
			count = 0;
			fm = 0;
			tempor.settemp(stof(value));  //orizo tis times tou ka8e antikeimenou pou 8a anate8ei sto vector
			tempor.settime(time);
			vec.push_back(tempor);       //pio katanohth h xrhsh 2 vector (vec -> o esoterikos)
			value = "";					//adeiazo ta periexomena tou mesa vector oste na mhn epanalambanontai oi metriseis
		}
		else if (count == 3 && x != '"') { //oso to count einai 3 kai den einai h 1h fora kata thn opoia to x == ' " ' briskomai mesa sta eisagogika pou periexoun thn timh ths 8ermokrasias pou 8elo na prospelaso
			value = value + x;
		}
		else if (x == '}') {
			vec_m.push_back(vec);
			vec.clear();			//skopos na mh menoun oi prohgoumenes meres kai na kratao mono thn trexousa
			x = NULL;
		}
		else if (x == '\n' || x == ':' || x == ',' || x == ' ') {
			//agnohse to
		}
	}
	//cout << vec_m.size();
	arx.close();
}