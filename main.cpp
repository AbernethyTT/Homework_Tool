#include <iostream>
using namespace std;
int main()
{
	char chose;
AS:
	cout << "Start enter '1'" << endl;
	cout << "Dont start ener '2'" << endl;
	cout << "Please enter '1' or '2' :";
	cin >> chose;
	if (chose =='1')
	{
		cout << "start";
	}
	else if (chose =='2')
	{
		cout << "Don't start";
	}
	 else {
		 goto AS;
	 }
	return 0;
}