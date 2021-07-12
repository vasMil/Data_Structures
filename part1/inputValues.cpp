#include "myHeader.h"
#include "inputValues.h"


inputValues::inputValues(float value, std::string time) {
		this->temp = value;
		this->timestamp = time;
	}

	void inputValues::settemp(float fvalue) {
		temp = fvalue;
	}
	void inputValues::settime(std::string strtime) {
		timestamp = strtime;
		itime = fixMeUp(strtime);

	}
	std::string inputValues::gettime() {
		return this->timestamp;
	}
	long long int inputValues::igettime() { //could break it into parts but I would need an overload for <
		return this->itime;				   //too lazy to do that
	}
	float inputValues::gettemp() {
		return this->temp;
	}

	void inputValues::printMeasur() {
		std::cout << "Timestamp: \t" << timestamp << "\nResOfMeasurment:\t" << temp << std::endl;
	}