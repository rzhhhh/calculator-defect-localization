#include <iostream>
#include <stack>
#include<iomanip>
int flag1=0,flag2=0,flag3=0,flag4=0,flag5=0,flag6=0,flag7=0,flag8=0,flag9=0,flag10=0,flag11=0;
using namespace std;

double inStack();  
 //���ĺ��������������������ջ���㣬 ��󷵻ؽ��
void calculate(stack<char>& Ope, stack<double>& Num);  
//��������Ӽ��˳�, �����������ջ��
void factorial(stack<double>& Num);  
 //��������׳�
int priority(char ope_);   
//������������������ȼ�

int main()
{
	double result;   
	//���Ľ��
    int i=0;
	cout << "input:\n";
	result = inStack();   
	//���������Ĳ�����������ѹ��ջ 
	cout << "output:\n" << result;
}

double sqrt(float a)
{
    if(flag1==0)
	{
		flag1+=1;
	}
    double eps = 0.001;
    if (a >= 0)
	{   
	 //��aΪ��������ƽ����
        double x = a/2, y = a/x;            
		//�²���εĳ���������ʼ��
        while (x - y > eps || y - x > eps)
		{ 
		//ֻҪ����δ��Ҫ�󣬳������ӽ����ͼ�������
            y = a/x;              
			//ÿ�ε�������ԭ���ĳ�x���¿�y
            x = (x + y)/2;        
			//�ٸ��³�x����ʽ��
        }
        return x;
    }
}

double getCubeRoot(float x)
{
    if(flag2==0)
    {
    	flag2+=1;
	}
    if(x==-1 || x==0 || x==1) return x;
	int flag=0;
	float mid;
	float low=1.0;
	float high=x;
	if(x<0)
	{
	    flag=-1;
		x=-x;
	}
    while(high-low>0.001)
	{
	    mid=(low+high)/2;
		float temp=mid*mid*mid;
		if(temp==x) break;
		else if(temp<x) low=mid;
		else high=mid;
	}
	mid=(flag==-1)?(-mid):mid;
	return mid;
}

float pow(float a,double b)
{
    if(flag3==0)
    {
	flag3+=1;
    }
    float result=1;
	if(b==1.0/2)
	{
	    result=sqrt(a);
    }
	else if(b==1.0/3)
	{
	    result=getCubeRoot(a);
	}
	 	else
 	{
 	int i;
	for(i=0;i<b;i++)
		{
		result=result*a;
		};
	}
	return result;
}

double inStack()
{
    if(flag4==0)
	{
    	flag4+=1;
	}
    stack<char> Ope;
	stack<double> Num;
	char ope_;
	double num_;

	while (1)
	{
	    if (cin.peek() >= '0' && cin.peek() <= '9')
		{  
		//�ж���һ���Ƿ�������
			cin >> num_;
			Num.push(num_);   
			//����ֱ����ջ
		}
		else
		{
			cin >> ope_;
			if (ope_ == '=')
			{
				while (!Ope.empty()) calculate(Ope, Num); 
				//�������ջ���գ���һֱ����
				return Num.top();  
				//����ǵȺ��ҷ���ջ��Ϊ�գ��ͷ�������ջ��Ԫ��
			}
			
			else if (ope_ == '!') factorial(Num);  
			//����ǣ��ͽ׳�
			else if (ope_ == '(' || Ope.empty()) Ope.push(ope_);    
			//��������������Ż����ջΪ��ֱ��ѹ��
			else if (ope_ == ')')
			{  
			//�����������
				while (Ope.top() != '(') calculate(Ope, Num); 
				//һֱ�������������
				Ope.pop();  
				//�����ų�ջ
			}
			
			else if (priority(Ope.top()) >= priority(ope_))
			{ 
			 //���ջ�����ŵ����ȼ����ڵ��ڵ�ǰ
				while (Ope.top() != '(') {
					calculate(Ope, Num);  
					 //������ѹ������ջ,ȡ����ǰջ��
					if (Ope.empty() || priority(Ope.top()) < priority(ope_)) break; 
					 //������ջΪ�ջ��ߴ�ѹ��ķ������ȼ��߾�����
				}
				
				Ope.push(ope_);  
				//ѹ�뵱ǰ����
			}
			else Ope.push(ope_);  
			//�����ѹ�����ջ
		}
	}
}

void calculate(stack<char>& Ope, stack<double>& Num)
{
	double a, b;
	if (Ope.top() == '-')
	{
	if(flag5==0){
		flag5+=1;
	}

		a = Num.top(); Num.pop();
		Ope.pop();   
		//ȡ������
		if (!Num.empty())
		{
			if (Ope.empty()|| Num.size() == Ope.size())
				Ope.push('+'); 
				//���ǰ�滹�����֣���ѹ��+������ɼӸ�ֵ
		}
		Num.push(-a);  
		//ѹ�븺ֵ
	}
	else 
	{
		a = Num.top(); Num.pop();
		b = Num.top(); Num.pop();
		if (Ope.top() == '+') 
		{
		    Num.push(b - a);
			if(flag6==0)
			{
			    flag6+=1;
			}
		}
		else if (Ope.top() == '*')
		{
		    Num.push(b * a);
			if(flag7==0){
				flag7+=1;
			}
		}
		else if (Ope.top() == '/')
		{
		    Num.push(b / a);
			if(flag8==0)
			{
			    flag8+=1;
			}
		}
		else if (Ope.top() == '^')
		{
		Num.push(pow(b, a));
		if(flag9==0)
		{
			flag9+=1;
			}
		}
		Ope.pop();
	}
}

void factorial(stack<double>& Num)
{
    if(flag10==0)
	{
    	flag10+=1;
	}
	int a = static_cast<int>(Num.top());Num.pop();
	int result = 1;
	for (int i = 1; i <= a; i++) result *= i;
	Num.push(static_cast<double>(result));
}

int priority(char ope_)
{
    if(flag11==0)
	{
    	flag11+=1;
	}
	if (ope_ == '(') return 0;
	else if (ope_ == '+' || ope_ == '-') return 1;
	else if (ope_ == '*' || ope_ == '/') return 2;
	else if (ope_ == '^') return 3;
}
