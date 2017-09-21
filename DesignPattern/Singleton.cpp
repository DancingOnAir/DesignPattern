//#include <iostream>
//#include <cstdlib>
//using namespace std;
//
//class Singleton
//{
//public:
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//
//	static Singleton* getInstance()
//	{
//		//if (nullptr == instance)
//		//	instance = new Singleton();
//		static Singleton* instance;
//		return instance;
//	}
//private:
//	Singleton();
//	//~Singleton();
//
//	//static Singleton* instance;
//};
//
//Singleton::Singleton()
//{
//
//}
//
////Singleton* Singleton::instance = new Singleton();
////Singleton* Singleton::getInstance()
////{
////	//if (nullptr == instance)
////	//{
////	//	instance = new Singleton();
////	//	cout << "Initialization" << endl;
////	//}
////
////	return instance;
////}
//
//int main(void)
//{
//
//	system("pause");
//	return 0;
//}