#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;

class Observer
{
public:
	virtual void Update(int) = 0;
};

class Subject
{
public:
	virtual void Attach(Observer *) = 0;
	virtual void Detach(Observer *) = 0;
	virtual void Notify() = 0;

};

class ConcreteObserver1 : public Observer
{
public:
	ConcreteObserver1(Subject* pSubject) : m_pSubject(pSubject) {}

	void Update(int val)
	{
		cout << "ConcreteObserver1 state is : " << val << endl;
	}

private:
	Subject* m_pSubject;

};

class ConcreteObserver2 : public Observer
{
public:
	ConcreteObserver2(Subject* pSubject) : m_pSubject(pSubject) {}

	void Update(int val)
	{
		cout << "ConcreteObserver2 state is : " << val << endl;
	}

private:
	Subject* m_pSubject;

};

class ConcreteSubject : public Subject
{
public:
	void Attach(Observer* pObserver)
	{
		pObserverList.push_back(pObserver);
	}


	void Detach(Observer* pObserver)
	{
		pObserverList.remove(pObserver);
	}

	void Notify()
	{
		for (auto iter = pObserverList.begin(); iter != pObserverList.end(); ++iter)
			(*iter)->Update(m_iState);
	}

	void SetState(int val)
	{
		m_iState = val;
	}

private:
	int m_iState;
	list<Observer*> pObserverList;
};

int main(void)
{
	ConcreteSubject* pSubject = new ConcreteSubject();
	Observer* pObserver1 = new ConcreteObserver1(pSubject);
	Observer* pObserver2 = new ConcreteObserver2(pSubject);

	pSubject->Attach(pObserver1);
	pSubject->Attach(pObserver2);

	pSubject->SetState(1);
	pSubject->Notify();

	pSubject->SetState(2);
	pSubject->Notify();

	pSubject->Detach(pObserver2);
	pSubject->SetState(3);
	pSubject->Notify();

	system("pause");
	return 0;
}