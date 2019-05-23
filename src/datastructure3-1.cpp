//============================================================================
// Name        : datastructure3-1.cpp
// Author      : Hyunju Kim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>//1�� linked list�� �ٽ� ����
#include <cstdlib>
using namespace std;

bool isOpen(char ch);//���°�ȣ Ȯ���ϴ� �Լ�
bool isClosed(char ch);//�ݴ°�ȣ Ȯ���ϴ� �Լ�
bool matches(char ch, char openSymbol);//¦�� �´��� Ȯ���ϴ� �Լ�


typedef char ItemType;

struct Node
{
	char info;//���� ���� ����
	Node* next;//Node* next ����
};


class Linkedstack
{
private:
	Node* topPtr;

public:
	Linkedstack();		                   // ���� ������
   ~Linkedstack();                     	   // ���� �Ҹ���
    bool isEmpty();				           // ����ִ��� Ȯ���ϴ� �Լ�
    bool isFull();				           // ���⼭ �Ⱦ�, �� ���ִ��� Ȯ���ϴ� �Լ�
    void push(ItemType ch);                // ���ÿ� ��� ����
    ItemType pop(); 	                   // ���� �ֱٿ� ���ÿ� ���Ե� ��Ҹ� �����ϰ� ��ȯ
    ItemType peek(); 	                   // ���� �ֱٿ� ���ÿ� ���Ե� ��Ҹ� ��ȯ
};


inline void error(char const *message)//�����޼��� ���
{
	cout<< message <<endl;
	exit(1);
}


Linkedstack::Linkedstack()//������
{
	topPtr=NULL;//NULL�� �ʱ�ȭ
}

Linkedstack::~Linkedstack()//�Ҹ���
{
	Node* tmpPtr;//������ ����

	while(topPtr!= NULL)//topPtr�� NULL�� �ƴҶ����� �ݺ�
	{
		tmpPtr=topPtr;
		topPtr=topPtr->next;//���� ������ �ٲ�
		delete tmpPtr;//�����Ҵ� ����
	}
}

bool Linkedstack::isEmpty()//������� Ȯ���ϴ� �Լ�
{
	return topPtr==NULL;//��������� -1��ȯ
}

bool Linkedstack::isFull()//�� ���ִ��� Ȯ��
{
	return 1;//�� ������
}


void Linkedstack::push(ItemType ch)//ch�� stack�� �Է�
{
		Node* newNode;//������ newNode ����
		newNode=new Node;//newNode�� Node ũ�⸸ŭ�� �����Ҵ�
		newNode->info=ch;//newNode�� ����Ű�� info�� ch�� ����
		newNode->next=topPtr;//newNode�� ����Ű�� next�� topPtr�ֱ�
		topPtr=newNode;//topPtr�� newNode�� �־��ֱ� �׷��� ����
		//topPtr�� ����Ű�� �ִ� ���� ���� �־��� ����
}

ItemType Linkedstack::pop()//pop�� �Լ�
{
	if(isEmpty())//���������
	{
		error("���� Empty");
		return 0;
	}

	else
	{
		ItemType item;
		Node* tmpPtr;//������ ���� ����
		item=topPtr->info;//topPtr�� ����Ű��info�� item�� ����

		tmpPtr=topPtr;//tmpPtr�� �ֱ�
		topPtr=topPtr->next;//topPtr�� ����Ű�� next�� �ٽ� �ޱ�
		delete tmpPtr;//tmpPtr ��ȯ

		return item;
	}

}

ItemType Linkedstack::peek()
{
	if(isEmpty())//������ִٸ�
	{
		error("���� Empty");
		return 0;
	}

	else
	{
		return topPtr->info;//topPtr�� ����Ű�� info�� ��ȯ
	}
}



int main()
{
	char ch;//���� ��ȣ
	Linkedstack list;//class stack ����
	bool balanced = true;//������ ��������� balanced
	char openSymbol;//���°�ȣ �ǹ�


	//���� filename���� ���� �Է�

	while(cin.get(ch) && balanced)//�� ���ھ� �Է¹ޱ�
	{
		if (isOpen(ch))//���°�ȣ�� ��
		{
			list.push(ch);//���ÿ� ����
		}

		else if(isClosed(ch))//�ݴ� ��ȣ�� ��
		{
			if(list.isEmpty())//����ִ��� Ȯ��, ���� ����ִٸ�
			{
				balanced=false;//¦�� ���� �ʴ�
			}

			else//������� �ʴٸ�
			{
				openSymbol=list.pop();//������ pop�� char�� openSymbol�� �ֱ�(���ʰ�ȣ)
				balanced=matches(ch, openSymbol);//ch�� openSymbol(���ʰ�ȣ)�� ¦�� ����
			}
		}
	}

	if(!balanced)//¦�� ���� ������
	{
		cout<<"-1"<<endl;//-1�� ���
	}

	else if(list.isEmpty() && balanced)//������ �� ����������� ¦�� �� �´ٴ� ��
	{
		cout<<"1"<<endl;
	}

	else
	{
		cout<<"-1"<<endl;
	}

	//sIN.close();
	return 0;
}




bool isOpen(char ch)//���� ��ȣ�� ������ �� �´��� Ȯ���ϴ� �Լ�
{
	if((ch =='(') || (ch =='{')|| (ch == '['))
	{
		return true;//������ ��
	}

	else
	{
		return false;//�ƴϸ� ����
	}
}

bool isClosed(char ch)//�ݴ� ��ȣ�� ������ ��
{
	if((ch == ')') || (ch == '}') ||(ch == ']'))
	{
		return true;//�̰� �� �ϳ��� ����
	}

	else
	{
		return false;//�ƴϸ� ����
	}
}

bool matches(char ch, char openSymbol)//¦�� �´��� Ȯ���ϴ� �Լ�
{
	if(((openSymbol == '(') && ch == ')') || ((openSymbol == '{') && ch == '}') || ((openSymbol == '[') && ch == ']'))
	{
		return true;//��
	}
	else//�ƴϸ�
	{
		return false;//����
	}
}
