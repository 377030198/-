#include<iostream>
#include<string>
using namespace std;
#define OVERFLOW -1
typedef struct
{   string name;
	int study_num;
	int room_num;
}message, * message_point;
typedef struct
{   message * a;  //存储空间基址
	int length;    //当前长度
	int lisesize;       //当前分配的存储容量
}SqList;
void InitList(SqList & L)//建立线性表函数
{   L.lisesize=20;//表的空间容量是20
	L.length=1;   //空表的长度为1
    L.a=new message[L.lisesize];

}
void zengtian(SqList & L)//增加函数
{	string b;
	if(L.length==L.lisesize)
cout<<"空间已满"<<endl;
	else
	{if(L.length==0)
		{cout<<"姓名:";cin>>L.a[1].name;
		cout<<"学号:";cin>>L.a[1].study_num;
		cout<<"房间号:";cin>>L.a[1].room_num;
		L.length++;
		}
		else
		{   cout<<"姓名:";cin>>L.a[L.length].name;
			cout<<"学号:";cin>>L.a[L.length].study_num;
			cout<<"房间号:";cin>>L.a[L.length].room_num;
			L.length++;
		}
		if(L.length==L.lisesize)  cout<<"空间已满"<<endl;
	}}
void shanchu(SqList & L)//删除函数
{   bool c=false;
	int i,j,b,k=L.length;
	if(L.length==1)  cout<<"空间已空"<<endl;
	else
	{  cout<<"输入删除学生的学号"<<endl;
		cin>>b;
		for(i=1;i<L.length;i++)
		{if(L.a[i].study_num==b)
			{c=true;for(j=i+1;j<L.length;j++)
			L.a[j-1]=L.a[j];
			}}
		if(c==true)
			L.length--;
		else
cout<<"该学生不存在"<<endl;
	}}
void xiugai(SqList & L)
{   bool c=false;
	int i,b;  cout<<"输入要修改的学生的学号"<<endl;
	cin>>b;  for(i=1;i<L.length;i++)
	{ if(L.a[i].study_num==b)
		{   c=true;
			cout<<"姓名:";cin>>L.a[i].name;
			cout<<"学号:";cin>>L.a[i].study_num;
			cout<<"房间号:";cin>>L.a[i].room_num;
		}}
	if(c==false)
	cout<<"该学生不存在"<<endl;
}
void shuchuxianshi(SqList L)//输出函数，显示学生信息
{   int i;
	if(L.length==1) cout<<"空间已空"<<endl;
	for(i=1;i<L.length;i++)
	{cout<<"学生姓名："<<L.a[i].name<<"  "<<"学号："<<L.a[i].study_num<<"  "<<"房间号："<<L.a[i].room_num<<endl;
}}
void paixu( SqList &L )
{                          // 对顺序表 L 作直接插入排序
int i,j;
	for ( i = 2; i <= L.length; ++i )
		if ( L.a[i].study_num < L.a[i-1].study_num )
		{ // 若"<"，则将 L.a[i].study_num 插入有序子表
			L.a[0].study_num = L.a[i].study_num; // 复制为哨兵
			for ( j = i-1; L.a[0].study_num < L.a[j].study_num ; --j )
			L.a[j+1].study_num = L.a[j].study_num; // 记录后移
			L.a[j+1].study_num = L.a[0].study_num; // 插入到正确位置
        } // if 结束;
        } // InsertSort
void chaxun_name(SqList L)
{  int i,j=0;string b;
	cout<<"输入待查询的学生的姓名"<<endl;
	cin>>b;  for(i=1;i<L.length;i++)
	{if(b==L.a[i].name)
		{  cout<<"姓名："<<L.a[i].name<<endl;
			cout<<"学号："<<L.a[i].study_num<<endl;
			cout<<"房间号："<<L.a[i].room_num<<endl;
			break;
		}
		j++;
	}
	if(j==(L.length-1))
		cout<<"该学生不存在"<<endl;
}
void chaxun_study_num(SqList L)
{
	int i,j=0;int b;
	cout<<"输入待查询的学生的学号"<<endl;
	cin>>b;for(i=1;i<L.length;i++)
	{ if(b==L.a[i].study_num)
		{  cout<<"姓名："<<L.a[i].name<<endl;
			cout<<"学号："<<L.a[i].study_num<<endl;
			cout<<"房间号："<<L.a[i].room_num<<endl;
			break;
		}j++;
	}
	if(j==(L.length-1))
cout<<"该学生不存在"<<endl;
}
void chaxun_room_num(SqList L)
{   int i,j=0;
	int b;cout<<"输入待查询的学生的房间号"<<endl;
	cin>>b;for(i=1;i<L.length;i++)
	{if(b==L.a[i].room_num)
		{   cout<<"姓名："<<L.a[i].name<<endl;
			cout<<"学号："<<L.a[i].study_num<<endl;
			cout<<"房间号："<<L.a[i].room_num<<endl;
			break;
		}
		j++;
	}
	if(j==(L.length-1))
		cout<<"该学生不存在"<<endl;
}
int main()
{    int s;char ch;  SqList L;
	InitList(L);
	do
	{
		cout<<"增加学生信息请输入a"<<endl;
		cout<<"删除学生信息请输入b"<<endl;
		cout<<"修改学生信息请输入c"<<endl;
		cout<<"显示学生信息请输入d"<<endl;
		cout<<"按学号排序请输入e"<<endl;
        cout<<"按姓名查询请输入f"<<endl;
		cout<<"按学号查询请输入g"<<endl;
		cout<<"按房间号查询请输入h"<<endl;
		cin>>ch;
		switch(ch)
		{
		case'a':  zengtian(L);  break;
		case'b':  shanchu(L);   break;
		case'c':  xiugai(L);    break;
		case'd':  shuchuxianshi(L); break;
        case'e':  paixu (L);    break;
		case'f':  chaxun_name(L);break;
		case'g':  chaxun_study_num(L);break;
		case'h':  chaxun_room_num(L);break;
		}
		cout<<"继续请输入"<<1<<endl;
		cout<<"退出请输入"<<0<<endl;
		cin>>s;
	}while(s==1);
	return 0;
}
