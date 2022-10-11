#pragma once
class FunctionHelper {
public:
	int getCharacteristic(int ch, int level, int shift) {
		int min = 0;
		int max = 0;
		for (int i = 0; i <= level; i++) {
			min += shift;
			max += shift;
			ch += randomRes(min, max);
		}

		return ch;
	}
	int randomRes(int min, int max) {
		if (min > max) {
			int c = min;
			min = max;
			max = c;
		}

		return min + rand() % (max - min + 1);
	}
};

