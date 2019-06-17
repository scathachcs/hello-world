#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Table {
public:
	Table(int a=1, int b=1) {
		Row = a;
		Column = b;
		cells=vector<Cell>(a * b);
	}
	void show() {
		for (int i = 1;i<=Row*Column;i++) {
			cells[i].show;
			if (i % Column == 0) {
				cout << endl;
			}
		}
	}
	int addRow(int a=1) {
		Cell s;
		for (int i = 0; i < a*Column; i++) {
			cells.push_back(s);
		}
		Row+=a;
	}
	void delRow(int a=1) {
		for (int i = 0; i < a * Column; i++) {
			cells.pop_back();
		}
		Row-=a;
	}
	int addColumn(int a=1) {
		Cell s;
		for (int i = 1; i < Row; i++) {
			cells.insert(cells.begin() + i*Column+1, s);
		}
		cells.push_back(s);
		Column+=a;

	}
	void delColumn(int a) {
		for (int i = 1; i <= Row; i++) {
			cells.erase(cells.begin() + i * Column);
		}
		Column -= a;
	}
	void set(int a, int b, string con) {
		cells[a * Row + b].setcon(con);
	}
	void set(int a, int b, int i) {
		cells[a * Row + b].setcon(i);
	}
private: 
	vector<Cell> cells;
	int Row;
	int Column;
};
class Cell {
public:
	Cell() {
	}
	Cell(char con[]) {
		content = con;
	}
	~Cell() {

	}
	void setcon(string con) {
		content = con;
	}
	void setcon(int i) {
		content = i;
	}
	void show() {
		cout << content << " ";
	}
private:
	string content;
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
