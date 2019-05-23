//============================================================================
// Name        : datastructure3-1.cpp
// Author      : Hyunju Kim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>//1번 linked list로 다시 구현
#include <cstdlib>
using namespace std;

bool isOpen(char ch);//오픈괄호 확인하는 함수
bool isClosed(char ch);//닫는괄호 확인하는 함수
bool matches(char ch, char openSymbol);//짝이 맞는지 확인하는 함수


typedef char ItemType;

struct Node
{
	char info;//정보 저장 변수
	Node* next;//Node* next 변수
};


class Linkedstack
{
private:
	Node* topPtr;

public:
	Linkedstack();		                   // 스택 생성자
   ~Linkedstack();                     	   // 스택 소멸자
    bool isEmpty();				           // 비어있는지 확인하는 함수
    bool isFull();				           // 여기서 안씀, 다 차있는지 확인하는 함수
    void push(ItemType ch);                // 스택에 요소 삽입
    ItemType pop(); 	                   // 가장 최근에 스택에 삽입된 요소를 삭제하고 반환
    ItemType peek(); 	                   // 가장 최근에 스택에 삽입된 요소를 반환
};


inline void error(char const *message)//에러메세지 출력
{
	cout<< message <<endl;
	exit(1);
}


Linkedstack::Linkedstack()//생성자
{
	topPtr=NULL;//NULL로 초기화
}

Linkedstack::~Linkedstack()//소멸자
{
	Node* tmpPtr;//포인터 선언

	while(topPtr!= NULL)//topPtr이 NULL이 아닐때까지 반복
	{
		tmpPtr=topPtr;
		topPtr=topPtr->next;//다음 값으로 바꿈
		delete tmpPtr;//동적할당 제거
	}
}

bool Linkedstack::isEmpty()//비었는지 확인하는 함수
{
	return topPtr==NULL;//비어있으면 -1반환
}

bool Linkedstack::isFull()//다 차있는지 확인
{
	return 1;//다 차있음
}


void Linkedstack::push(ItemType ch)//ch을 stack에 입력
{
		Node* newNode;//포인터 newNode 생성
		newNode=new Node;//newNode에 Node 크기만큼의 동적할당
		newNode->info=ch;//newNode가 가르키는 info에 ch값 저장
		newNode->next=topPtr;//newNode가 가르키는 next에 topPtr넣기
		topPtr=newNode;//topPtr에 newNode값 넣어주기 그러면 지금
		//topPtr이 가르키고 있는 값이 지금 넣어준 값임
}

ItemType Linkedstack::pop()//pop할 함수
{
	if(isEmpty())//비어있으면
	{
		error("스택 Empty");
		return 0;
	}

	else
	{
		ItemType item;
		Node* tmpPtr;//포인터 변수 선언
		item=topPtr->info;//topPtr이 가르키는info값 item에 저장

		tmpPtr=topPtr;//tmpPtr에 넣기
		topPtr=topPtr->next;//topPtr은 가르키는 next값 다시 받기
		delete tmpPtr;//tmpPtr 반환

		return item;
	}

}

ItemType Linkedstack::peek()
{
	if(isEmpty())//비워져있다면
	{
		error("스택 Empty");
		return 0;
	}

	else
	{
		return topPtr->info;//topPtr이 가르키는 info값 반환
	}
}



int main()
{
	char ch;//넣을 괄호
	Linkedstack list;//class stack 선언
	bool balanced = true;//스택이 비어있으면 balanced
	char openSymbol;//오픈괄호 의미


	//파일 filename으로 부터 입력

	while(cin.get(ch) && balanced)//한 문자씩 입력받기
	{
		if (isOpen(ch))//여는괄호일 때
		{
			list.push(ch);//스택에 저장
		}

		else if(isClosed(ch))//닫는 괄호일 때
		{
			if(list.isEmpty())//비어있는지 확인, 만약 비어있다면
			{
				balanced=false;//짝이 맞지 않다
			}

			else//비어있지 않다면
			{
				openSymbol=list.pop();//스택의 pop할 char을 openSymbol에 넣기(왼쪽괄호)
				balanced=matches(ch, openSymbol);//ch와 openSymbol(왼쪽괄호)의 짝이 맞음
			}
		}
	}

	if(!balanced)//짝이 맞지 않으면
	{
		cout<<"-1"<<endl;//-1값 출력
	}

	else if(list.isEmpty() && balanced)//스택이 다 비워져있으면 짝이 다 맞다는 말
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




bool isOpen(char ch)//여는 괄호가 들어왔을 때 맞는지 확인하는 함수
{
	if((ch =='(') || (ch =='{')|| (ch == '['))
	{
		return true;//맞으면 참
	}

	else
	{
		return false;//아니면 거짓
	}
}

bool isClosed(char ch)//닫는 괄호가 들어왔을 때
{
	if((ch == ')') || (ch == '}') ||(ch == ']'))
	{
		return true;//이것 중 하나면 참임
	}

	else
	{
		return false;//아니면 거짓
	}
}

bool matches(char ch, char openSymbol)//짝이 맞는지 확인하는 함수
{
	if(((openSymbol == '(') && ch == ')') || ((openSymbol == '{') && ch == '}') || ((openSymbol == '[') && ch == ']'))
	{
		return true;//참
	}
	else//아니면
	{
		return false;//거짓
	}
}
