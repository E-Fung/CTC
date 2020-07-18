#include "check.h"

check::check() {
	valid = false;
	data = 0;
}

bool check::getBool() {
	return valid;
}

int check::getData() {
	return data;
}

void check::setBool(bool set) {
	valid = set;
}

void check::setData(int set) {
	data = set;
}
