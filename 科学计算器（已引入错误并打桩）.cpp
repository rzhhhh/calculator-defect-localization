#include <iostream>
#include <stack>
#include<iomanip>
int flag1=0,flag2=0,flag3=0,flag4=0,flag5=0,flag6=0,flag7=0,flag8=0,flag9=0,flag10=0,flag11=0;
using namespace std;

double inStack();  
 //核心函数，将操作符有序的入栈计算， 最后返回结果
void calculate(stack<char>& Ope, stack<double>& Num);  
//用来计算加减乘除, 结果放在数字栈顶
void factorial(stack<double>& Num);  
 //用来计算阶乘
int priority(char ope_);   
//用来计算操作符的优先级

int main()
{
	double result;   
	//最后的结果
    int i=0;
	cout << "input:\n";
	result = inStack();   
	//将缓冲区的操作符和数字压入栈 
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
	 //若a为正，可求平方根
        double x = a/2, y = a/x;            
		//猜测矩形的长、宽，并初始化
        while (x - y > eps || y - x > eps)
		{ 
		//只要精度未达要求，长宽不够接近，就继续迭代
            y = a/x;              
			//每次迭代先用原来的长x更新宽y
            x = (x + y)/2;        
			//再更新长x（公式）
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
		//判断下一个是否是数字
			cin >> num_;
			Num.push(num_);   
			//数字直接入栈
		}
		else
		{
			cin >> ope_;
			if (ope_ == '=')
			{
				while (!Ope.empty()) calculate(Ope, Num); 
				//如果符号栈不空，就一直计算
				return Num.top();  
				//如果是等号且符号栈顶为空，就返回数字栈顶元素
			}
			
			else if (ope_ == '!') factorial(Num);  
			//如果是！就阶乘
			else if (ope_ == '(' || Ope.empty()) Ope.push(ope_);    
			//如果符号是左括号或符号栈为空直接压入
			else if (ope_ == ')')
			{  
			//如果是右括号
				while (Ope.top() != '(') calculate(Ope, Num); 
				//一直计算完括号里的
				Ope.pop();  
				//左括号出栈
			}
			
			else if (priority(Ope.top()) >= priority(ope_))
			{ 
			 //如果栈顶符号的优先级大于等于当前
				while (Ope.top() != '(') {
					calculate(Ope, Num);  
					 //计算结果压入数字栈,取出当前栈顶
					if (Ope.empty() || priority(Ope.top()) < priority(ope_)) break; 
					 //当符号栈为空或者待压入的符号优先级高就跳出
				}
				
				Ope.push(ope_);  
				//压入当前符号
			}
			else Ope.push(ope_);  
			//否则就压入符号栈
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
		//取出负号
		if (!Num.empty())
		{
			if (Ope.empty()|| Num.size() == Ope.size())
				Ope.push('+'); 
				//如果前面还有数字，就压入+，即变成加负值
		}
		Num.push(-a);  
		//压入负值
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
