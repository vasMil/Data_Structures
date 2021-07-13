#include "Part2Header.h"
#include "node.h"
#include "string.h"
#include <typeinfo>


class node;



int getDayFile(std::fstream& arx, int pos) {
	char b;
	std::string str, temp;
	arx.seekg(pos);
	do {
		arx.get(b);
		if (b != '{' && b != '"' && b != '-' && b != 'T')
			str = str + b;
	} while (b != 'T' && arx.is_open());

	return stoi(str);
}


float averageTemps(std::fstream& arx, int pos) {
	int i;
	char t;
	std::string str;

	arx.seekg(pos);

	for (i = 0; i < 25; i++) {
		arx.get(t);
	}
	do {
		arx.get(t);
		if (t != '"' && t != ':') {
			str = str + t;
		}
	} while (t != '"' && arx.is_open());
	arx.get(t);
	return stof(str);
}


void GetMyNode(std::string filename, std::vector<node>& vect) {
	node tempor;
	int pos = 0;
	int i = 0, counter = 0;
	char x;

	std::fstream arx;
	arx.open(filename.c_str(), std::ios::in);

	while (!arx.eof() && arx.is_open()) {
		counter++;
		tempor.setDay(getDayFile(arx, pos));
		vect.push_back(tempor);
		arx.seekg(pos);

		i = 0;
		do {
			arx.get(x);
			i++;
		} while (x != '}');

		if (arx.peek() == EOF) {
			arx.close();
		}
		else {
			pos = pos + i + 1;
			arx.seekg(pos);
		}
	}

	arx.open(filename.c_str(), std::ios::in);
	float av = 0;
	int cnt2 = 0;
	pos = 0;

	for (i = 0; i < counter; i++) { //pername to arxeio 2h fora --> mporei na apofeux8ei (opos sto part1) --> htan apla mia nea idea p 8elame na ulopoihsoume

		while (x != '\n' && x != EOF) {
			pos = (int)arx.tellg();
			av = av + averageTemps(arx, pos);
			cnt2++;
			x = arx.peek();
			if(x == '\r'){ x = '\n'; break; }
		}
		if (x == '\n') {
			pos = (int)arx.tellg();
			pos += 2;
			arx.seekg(pos);
			x = '0';
		}
		av = av / cnt2;
		vect[i].setAvTemp(av);
		av = 0;
		cnt2 = 0;
	}
	arx.close();
}