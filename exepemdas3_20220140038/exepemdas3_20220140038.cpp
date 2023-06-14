#include <iostream>
#include <vector>
using namespace std;

class penerbit;
class pengarang {
public:
	string nama;
	vector<penerbit*> daftar_penerbit;
	pengarang(string pNama) :nama(pNama) {
		cout << "Pengarang \"" << nama << "\" ada\n";
	}
	~pengarang() {
		cout << "Pengarang \"" << nama << "\" tidak ada\n";
	}
	void tambahpenerbit(penerbit*);
	void cetakpenerbit();
};

class penerbit {
public:
	string nama;
	vector<pengarang*> daftar_pengarang;

	penerbit(string pNama) :nama(pNama) {
		cout << "Penerbit \"" << nama << "\" ada\n";
	}
	~penerbit() {
		cout << "Penerbit \"" << nama << "\" tidak ada\n";
	}

	void tambahpengarang(pengarang*);
	void cetakpengarang();
	void cetakpenerbit();
	void tambahpenerbit();
};

void pengarang::tambahpenerbit(penerbit* penerbit) {
	daftar_penerbit.push_back(penerbit);
}
void pengarang::cetakpenerbit() {
	cout << "Daftar pengarang dari penerbit \"" << this->nama << "\":\n";
	for (auto& a : daftar_penerbit) {
		cout << a->nama << "\n";
	}
	cout << endl;
}
void penerbit::tambahpengarang(penerbit* ppenerbit) {
	daftar_pengarang.push_back(pengarang);
	pengarang->tambahpenerbit();
}
void penerbit::cetakpengarang() {
	cout << "Daftar pengarang dari penerbit \"" << this->nama << "\":\n";
	for (auto& a : daftar_pengarang) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

int main() {
	penerbit* varpenerbit1 = new penerbit("GamaPress");
	penerbit* varpenerbit2 = new penerbit("IntanPariwara");
	pengarang* varpengarang1 = new pengarang("Joko");
	pengarang* varpengarang2 = new pengarang("Lia");
	pengarang* varpengarang3 = new pengarang("Giga");

	varpenerbit1->tambahpengarang(varpengarang1);
	varpenerbit1->tambahpengarang(varpengarang2);
	varpenerbit2->tambahpengarang(varpengarang1);
	varpenerbit1->tambahpengarang(varpengarang2);

	varpenerbit1->cetakpengarang();
	varpenerbit2->cetakpengarang();
	varpengarang1->cetakpenerbit();
	varpengarang2->cetakpenerbit();

	delete varpengarang1;
	delete varpengarang2;
	delete varpenerbit1;
	delete varpenerbit2;

	return 0;
}