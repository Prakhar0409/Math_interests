#include<iostream>
#include<iomanip>
using namespace std;

class complex
{
private:
	float real;
	float img;

public:
	complex(){real=0.0;img=0.0;}
	complex(float x,float y){real=x;img=y;}
	void set_r(float x){real=x;}
	void set_i(float x){img=x;}
	float get_r(){return real;}
	float get_i(){return img;}
	float size(){return real*real+img*img;}
	complex square(){return complex(real*real-img*img,2*real*img);}
	complex operator +( complex a){
		complex y;
		y.set_r(real+a.get_r());
		y.set_i(img+a.get_i());
		return y;
			
		
	}
};

int mandel1(complex c)
{
	complex z;
	//cout<<c.get_r()<<" "<<c.get_i();
	int count=0;
	//complex z1;
	do{
		z=z.square()+c;count++;
	}while(z.size()<5 && count<100);
	if(count<99)return 1;
	return 0;
	
}

int  main()
{
	int left=-2;
	int top=1;
	float width=3.25/45.0;
	float height=2.0/30.0;
	//cout<<width<<endl;
	for(int i=0;i<30;i++)
	{
		for(int j=1;j<45;j++)
		{
			int color=mandel1(complex(left+j*width,top-i*height));
			
			cout<<setw(2)<<color;
		}
		cout<<endl;
	}	

	
}
