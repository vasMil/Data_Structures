#pragma once

class inputValues {
public:
	inputValues() {
		temp = 0;
		itime = 0;
		timestamp = "NoValue";
	}
	inputValues(float value, std::string time);
	void settemp(float fvalue);
	void settime(std::string strtime);
	std::string gettime();
	long long int igettime();
	float gettemp();
	void printMeasur(); //Prints object in a nice format kappa
private:
	float temp;
	long long int itime;
	std::string timestamp;
};