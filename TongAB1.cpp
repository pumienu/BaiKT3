#include <iostream>
using namespace std;

class Cong{
	private:
	    int num1, num2;
	public:
	    Cong(int a, int b) : num1(a), num2(b){}
	    double sum(){
	        return num1 + num2;
	    }
};

int main() {
    int a, b;
    cin >> a >> b;
    Cong cong(a, b);
    cout << cong.sum();
    return 0;
}