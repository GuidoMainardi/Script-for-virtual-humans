#ifndef POSITION_H
#define POSITION_H
#include <iostream>
#include <string>

using namespace std;

class Position {
	private:
		int x;
		int y;
		int z;
	public:
		Position(int a, int b, int c) { x = a; y = b; z = c; }
		Position() { x = y = z = 0; }
		int getX() { return x; }
		int getY() { return y; }
		int getZ() { return z; }
		string tostring() {
			return "(" + to_string(x) + "," + to_string(y) + ","
				+ to_string(z) + ")";
		}
};
#endif
