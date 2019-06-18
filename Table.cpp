#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class Cell {
public:
	Cell() {
		content = " ";
	}

	Cell(char con[]) {
		content = con;
	}

	~Cell() {

	}

	void setcon(string con) {
		content = con;
	}

	void show() {
		cout << content << " ";
	}
private:
	string content;
};

class Table {
public:
	Table(int a = 1, int b = 1) {
		Row = a;
		Column = b;
	}

	void show() {
		for (int i = 0; i < Row ; i++) {
			for (int j = 0; j < Column; j++) {
				cells[i][j].show();
				cout << "|";
			}
			cout << endl;
			if (i == Row - 1) {
				cout << "_________________________endtable";
				cout << endl;
			}
		}
	}
	void addRow(int a = 1) {
		Row += a;
	}
	void delRow(int a = 1) {
		Row -= a;
	}
	void addColumn(int a = 1) {
		Column += a;

	}
	void delColumn(int a=1) {
		Column -= a;
	}
	void set(int a, int b, string con) {
		cells[a][b].setcon(con);
	}
	void set(int a, int b, int i) {
		stringstream ss;
		ss << i;
		string con;
		ss >> con;
		cells[a][b].setcon(con);
	}
private:
	Cell cells[10][10];
	int Row;
	int Column;
};


int main() {
	Table tb;
	tb.show();
	tb.addRow();
	tb.show();
	tb.addColumn();
	tb.show();
	Table tb1(5, 5);
	tb1.show();
	tb1.set(1, 1, 30);
	tb1.set(2, 2, "hello");
	tb1.show();
	tb1.delRow(1);
	tb1.show();
	tb1.delColumn(1);
	tb1.show();
	return 0;
} 
