#include <bits/stdc++.h>

using namespace std;

class Box{
    private :
        int lenght, breadth, height;

    public :
        Box(){
            lenght = 0;
            breadth = 0;
            height = 0;
        };

        Box(Box& boxToBeCopied){
            lenght = boxToBeCopied.getLenght();
            breadth = boxToBeCopied.getBreadth();
            height = boxToBeCopied.getHeight();
        };

        Box(int l, int b, int h){
            lenght = l;
            breadth = b;
            height = h;
        };

        int getLenght(){
            return lenght;
        };

        int getBreadth(){
            return breadth;
        };

        int getHeight(){
            return height;
        };

        long CalculateVolume(){
            long volume;
            volume = lenght * breadth;
            volume *= height;
            return  volume;
        };

        bool operator<(Box& b){
            return (lenght < b.getLenght()) 
                || (lenght == b.getLenght() && breadth < b.breadth)
                || (lenght == b.getLenght() && breadth == b.breadth && height < b.getHeight());
        };

        friend ostream& operator<<( ostream& out, Box& B){
            out << B.getLenght() << " " << B.getBreadth() << " " << B.getHeight();
            return out;
        }

};


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}