#include <iostream>
using namespace std;
float get_much_wine(int C,int L,int x,int y);
float get_wine_amount(int C,int L,int n)
{
	float ret = 0, x, y;
	for(x = 1;;x++)
	{
		if(((x+1)*x)/2>=n)
			break;
	}
	y = n - ((x-1)*x)/2;
    // cout << x << " " << y << " ";
	ret = get_much_wine(C,L,x,y);
	return ret > C?C:ret;
}
float get_much_wine(int C,int L,int x,int y)
{
	if(x==1&&y==1)
		return L;
	float ret = 0;
	if(y == 1||y == x)
	{
		ret = 1.0*(get_much_wine(C,L,x-1,1)-C)/2;
		// cout << x << " " << y << " " << ret << " ";
		return ret >0?ret:0;
	}
	float left = get_much_wine(C,L,x-1,y-1)-C;
	left = left>0?left:0;
	float right = get_much_wine(C,L,x-1,y)-C;
	right = right>0?right:0;
	ret = (left+right)/2;
	return ret>0?ret:0;
}
int main()
{
	for(int i=1;i<20;i++)
		cout << get_wine_amount(2,20,i)<<" ";
	return 0;
}