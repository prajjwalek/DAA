#include<iostream>
using namespace std;

class greedy
{
	public:
		int id;
		float wt;
		float pft;
		float pw;
		float amt;
		
		void ratio()
		{
			pw = pft/wt;
		}
};

int main()
{
	int n;
	float cp,totalw,totalp;
	cout<<"Enter number of obj.: ";
	cin>>n;
	cout<<"Enter bag capacity: ";
	cin>>cp;
	
	greedy obj[n];
	
	for(int i=0;i<n;i++)
	{
		obj[i].amt=0;
		obj[i].id=i+1;
		cout<<"\nEnter weight of object: ";
		cin>>obj[i].wt;
		cout<<"Enter profit of object: ";
		cin>>obj[i].pft;
	}
	
	cout<<"pw values: ";
	for(int i=0;i<n;i++)
	{
		obj[i].ratio();
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<"\n\t"<<obj[i].pw;
	}
	
	int i=0;
	
	cout<<"\n"<<"T.Profit"<<"\t"<<"T.Weight"<<"\n";
	while(1)
	{
		if(totalw<cp)
		{
			if(obj[i].wt <= (cp-totalw))
			{
				obj[i].amt=1;
				totalw+=obj[i].wt;
				totalp+=obj[i].pft;
				
				cout<<"\n"<<totalp<<"\t\t"<<totalw<<"\n";
			}
			
			else if(obj[i].wt > (cp-totalw))
			{
				obj[i].amt = (cp-totalw)/obj[i].wt;
				totalw+=(cp-totalw);
				totalp+=((obj[i].amt)*(obj[i].pft));
				
				cout<<"\n"<<totalp<<"\t\t"<<totalw<<"\n";
			}
		}
		else
		{
			break;
		}
		i++;
	}
	
	cout<<"\n"<<"id"<<"\t"<<"amount"<<"\t\t"<<"weight"<<"\t"<<"profit"<<"\t"<<"pw\n";
	for(int i=0;i<n;i++)
	{
		cout<<obj[i].id<<"\t"<<obj[i].amt<<"\t\t";
		cout<<obj[i].wt<<"\t";
		cout<<obj[i].pft<<"\t";
		cout<<obj[i].pw<<"\n";
	}
	cout<<"\n"<<"Total profit is: "<<totalp;
}
