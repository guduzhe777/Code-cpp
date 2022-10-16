#include<iostream>
#include<string>

using namespace std;
class Object
{
public:
   Object()
	{
		cout << "Beginning" << endl;
	}
	~Object(void)
	{
		cout << "End" << endl;
	}


   

};



int main()
{

   Object app;

   system("pause");


   return 0;
}