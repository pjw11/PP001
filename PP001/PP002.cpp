#include <iostream>

using namespace std;

class Car
{
public:
	Car()
	{
		cout << "Car를 생성합니다\n";
	}
	~Car()
	{
		cout << "Car가 소멸됩니다\n";
	}
	void OpenWindow()
	{
		cout << "창문을 엽니다\n";
	}
	void ChangeGear()
	{
		cout << "기어를 변경합니다\n";
	}
};

class Spark : public Car
{
public:
	Spark()	
	{
		cout << "Spark를 생성합니다\n";
	}
	~Spark()
	{
		cout << "Spark가 소멸됩니다\n";
	}
};
class Escalade : public Car
{
public:
	Escalade()
	{
		cout << "Escalade를 생성합니다\n";
	}
	~Escalade()
	{
		cout << "Escalade가 소멸됩니다\n";
	}
	void OpenWindow()
	{
		cout << "자동으로 창문을 엽니다\n";
	}
	void ChangeGear()
	{
		cout << "자동으로 기어를 바꿉니다\n";
	}
};
//운전자 함수
void main()
{
	Car* c[2];
	c[0] = new Spark();
	c[1] = new Escalade();

	for (size_t i = 0; i < 2; i++)
	{
		c[i]->OpenWindow();
		c[i]->ChangeGear();
		delete(c[i]);
	}

}