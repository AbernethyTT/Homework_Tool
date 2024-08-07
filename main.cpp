#include <iostream>
using namespace std;
int main()
{
	char chose;
	char user_a = 1;
	char user_s= 2;
AS:
	cout << "Start enter '1'" << endl;
	cout << "Dont start ener '2'" << endl;
	cout << "Please enter 1 or 2 :";
	cin >> chose;
	if (chose =1)
	{
		cout << "start";
	}
	if (chose =2)
	{
		cout << "d";
	}
	 else {
		 goto AS;
	 }
	return 0;
}