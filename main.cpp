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
{   message * a;  //�洢�ռ��ַ
	int length;    //��ǰ����
	int lisesize;       //��ǰ����Ĵ洢����
}SqList;
void InitList(SqList & L)//�������Ա���
{   L.lisesize=20;//��Ŀռ�������20
	L.length=1;   //�ձ�ĳ���Ϊ1
    L.a=new message[L.lisesize];

}
void zengtian(SqList & L)//���Ӻ���
{	string b;
	if(L.length==L.lisesize)
cout<<"�ռ�����"<<endl;
	else
	{if(L.length==0)
		{cout<<"����:";cin>>L.a[1].name;
		cout<<"ѧ��:";cin>>L.a[1].study_num;
		cout<<"�����:";cin>>L.a[1].room_num;
		L.length++;
		}
		else
		{   cout<<"����:";cin>>L.a[L.length].name;
			cout<<"ѧ��:";cin>>L.a[L.length].study_num;
			cout<<"�����:";cin>>L.a[L.length].room_num;
			L.length++;
		}
		if(L.length==L.lisesize)  cout<<"�ռ�����"<<endl;
	}}
void shanchu(SqList & L)//ɾ������
{   bool c=false;
	int i,j,b,k=L.length;
	if(L.length==1)  cout<<"�ռ��ѿ�"<<endl;
	else
	{  cout<<"����ɾ��ѧ����ѧ��"<<endl;
		cin>>b;
		for(i=1;i<L.length;i++)
		{if(L.a[i].study_num==b)
			{c=true;for(j=i+1;j<L.length;j++)
			L.a[j-1]=L.a[j];
			}}
		if(c==true)
			L.length--;
		else
cout<<"��ѧ��������"<<endl;
	}}
void xiugai(SqList & L)
{   bool c=false;
	int i,b;  cout<<"����Ҫ�޸ĵ�ѧ����ѧ��"<<endl;
	cin>>b;  for(i=1;i<L.length;i++)
	{ if(L.a[i].study_num==b)
		{   c=true;
			cout<<"����:";cin>>L.a[i].name;
			cout<<"ѧ��:";cin>>L.a[i].study_num;
			cout<<"�����:";cin>>L.a[i].room_num;
		}}
	if(c==false)
	cout<<"��ѧ��������"<<endl;
}
void shuchuxianshi(SqList L)//�����������ʾѧ����Ϣ
{   int i;
	if(L.length==1) cout<<"�ռ��ѿ�"<<endl;
	for(i=1;i<L.length;i++)
	{cout<<"ѧ��������"<<L.a[i].name<<"  "<<"ѧ�ţ�"<<L.a[i].study_num<<"  "<<"����ţ�"<<L.a[i].room_num<<endl;
}}
void paixu( SqList &L )
{                          // ��˳��� L ��ֱ�Ӳ�������
int i,j;
	for ( i = 2; i <= L.length; ++i )
		if ( L.a[i].study_num < L.a[i-1].study_num )
		{ // ��"<"���� L.a[i].study_num ���������ӱ�
			L.a[0].study_num = L.a[i].study_num; // ����Ϊ�ڱ�
			for ( j = i-1; L.a[0].study_num < L.a[j].study_num ; --j )
			L.a[j+1].study_num = L.a[j].study_num; // ��¼����
			L.a[j+1].study_num = L.a[0].study_num; // ���뵽��ȷλ��
        } // if ����;
        } // InsertSort
void chaxun_name(SqList L)
{  int i,j=0;string b;
	cout<<"�������ѯ��ѧ��������"<<endl;
	cin>>b;  for(i=1;i<L.length;i++)
	{if(b==L.a[i].name)
		{  cout<<"������"<<L.a[i].name<<endl;
			cout<<"ѧ�ţ�"<<L.a[i].study_num<<endl;
			cout<<"����ţ�"<<L.a[i].room_num<<endl;
			break;
		}
		j++;
	}
	if(j==(L.length-1))
		cout<<"��ѧ��������"<<endl;
}
void chaxun_study_num(SqList L)
{
	int i,j=0;int b;
	cout<<"�������ѯ��ѧ����ѧ��"<<endl;
	cin>>b;for(i=1;i<L.length;i++)
	{ if(b==L.a[i].study_num)
		{  cout<<"������"<<L.a[i].name<<endl;
			cout<<"ѧ�ţ�"<<L.a[i].study_num<<endl;
			cout<<"����ţ�"<<L.a[i].room_num<<endl;
			break;
		}j++;
	}
	if(j==(L.length-1))
cout<<"��ѧ��������"<<endl;
}
void chaxun_room_num(SqList L)
{   int i,j=0;
	int b;cout<<"�������ѯ��ѧ���ķ����"<<endl;
	cin>>b;for(i=1;i<L.length;i++)
	{if(b==L.a[i].room_num)
		{   cout<<"������"<<L.a[i].name<<endl;
			cout<<"ѧ�ţ�"<<L.a[i].study_num<<endl;
			cout<<"����ţ�"<<L.a[i].room_num<<endl;
			break;
		}
		j++;
	}
	if(j==(L.length-1))
		cout<<"��ѧ��������"<<endl;
}
int main()
{    int s;char ch;  SqList L;
	InitList(L);
	do
	{
		cout<<"����ѧ����Ϣ������a"<<endl;
		cout<<"ɾ��ѧ����Ϣ������b"<<endl;
		cout<<"�޸�ѧ����Ϣ������c"<<endl;
		cout<<"��ʾѧ����Ϣ������d"<<endl;
		cout<<"��ѧ������������e"<<endl;
        cout<<"��������ѯ������f"<<endl;
		cout<<"��ѧ�Ų�ѯ������g"<<endl;
		cout<<"������Ų�ѯ������h"<<endl;
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
		cout<<"����������"<<1<<endl;
		cout<<"�˳�������"<<0<<endl;
		cin>>s;
	}while(s==1);
	return 0;
}
