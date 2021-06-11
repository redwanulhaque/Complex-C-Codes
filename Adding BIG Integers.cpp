#include<iostream>
using namespace std;

string add(string a, string b)
{
	if(a.length() < b.length())
	swap(a, b);

	int x = a.length()-1;
	for(int i=b.length()-1; i>=0; i--, x--)
		a[x]+=(b[i]-'0');

	for(int i=a.length()-1; i>0; i--){
		if(a[i] > '9'){
		int d = a[i]-'0';
		a[i-1] = ((a[i-1]-'0') + d/10) + '0';
		a[i] = (d%10)+'0';}
	}

	if(a[0] > '9'){
		string y;
		y+=a[0];
		a[0] = ((a[0]-'0')%10)+'0';
		y[0] = ((y[0]-'0')/10)+'0';
		a = y+a;
	}
	return a;
}

int main(){

	string n1;
	string n2;
	string terminate = "done";

	cout << "Enter a number: ";
	cin >> n1;

	if(n1.length()>100){
		return 0;}

	if(n1==terminate){
		return 0;}

	cout << "Enter another number: ";
	cin >> n2;

	if(n2.length()>100){
		return 0;}

	cout << n1 << " + " << n2 << " = " << add(n1,n2);

	return 0;
}

