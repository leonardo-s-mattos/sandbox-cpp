#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
        long intA = A;
        //printf("%#x\n", intA); 
        //cout << intA << "  "  << A << endl;
        char buffer[100];
        cout << std::resetiosflags(std::ios::showbase);
        cout << hex << nouppercase << showbase;
        //std::cout << std::hex ;
        cout << left << intA << endl;

        cout << std::resetiosflags(std::ios::showbase);
        cout << setfill ('_') << std::setw (15);
        sprintf (buffer, "%+.2f", B);
        cout << right << buffer << endl;
        
        cout << std::resetiosflags(std::ios::showbase);
        cout << setprecision(9) << setw (15) << scientific << uppercase;
        cout << right << C << endl;
        //printf("%15.9E\n", C);

	}
	return 0;

}