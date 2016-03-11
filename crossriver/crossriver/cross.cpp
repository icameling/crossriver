#include <iostream>

using namespace std;

int businesss_man = 3, followers = 3;
char g[3][2] = {{0,2},{2,0},{1,1}};
char b[3][2] = {{1,0},{0,1},{1,1}};

bool cross_river(int business1, int foll1, int business2, int foll2);
static int k = 0;

int main()
{
	//int businesss_man = 3, followers = 3;
	cout<<"(business, "<<"foll)"<<endl;
	cout<<'('<<businesss_man<<", "<<followers<<')'<<endl<<endl;
	cross_river(businesss_man,followers,0,0);
	cout << "Hello world!" << endl;
	return 0;
}

bool cross_river(int business1, int foll1, int business2, int foll2)
{
	if (k > 1000)
	{
		cout<<"no answer"<<endl;
		return false;
	}
	if((business1 < foll1) && business1 > 0)
		return false;
	if((business2 < foll2) && business2 > 0)
		return false;
	if(business1 < 0 || business2 < 0 || foll1 < 0 || foll2 < 0)
		return false;
	if(business1 == 0 && foll1 == 0 )
		return true;

	k++;
	if (k % 2 == 1)//go
	{
		for(int i = 0; i<3; i++)
			if(cross_river(business1-g[i][0],foll1-g[i][1],business2+g[i][0],foll2+g[i][1]))
			{
				cout<<k<<"("<<business1<<", "<<foll1<<")"
					<<'('<<business2<<", "<<foll2<<')';
				cout<<"----->("<<business1-g[i][0]<<", "<<foll1-g[i][1]<<")"
					<<'('<<business2+g[i][0]<<", "<<foll2+g[i][1]<<')'<<endl;
				k--;
				return true;
			}
	}
	else//back
	{
		for(int i = 0; i<3; i++)
			if(cross_river(business1+b[i][0],foll1+b[i][1],business2-b[i][0],foll2-b[i][1]))
			{
				cout<<k<<"("<<business1+b[i][0]<<", "<<foll1+b[i][1]<<")"
					<<'('<<business2-b[i][0]<<", "<<foll2-b[i][1]<<')';
				cout<<"<----("<<business1<<", "<<foll1<<")"
					<<'('<<business2<<", "<<foll2<<')'<<endl;
				k--;
				return true;	
			}
	}
	
	return false;
}
