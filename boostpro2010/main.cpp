#include <boost/thread/thread.hpp>
#include <iostream>
#include <boost/threadpool.hpp>
#include <boost/pool/pool.hpp>
#include <boost/shared_ptr.hpp>

class Simple
{
public:
	Simple(int param = 0)
	{
		int a;
		int b;
		m_number = param;
		std::cout << "Simple: " << m_number << std::endl;
	}

	~Simple()
	{
		std::cout << "~Simple: " << m_number << std::endl;
	}

	void Print()
	{
		std::cout << "Print: " << m_info.c_str() << std::endl;
	}

	std::string m_info;
	int t;
private:
	int m_number;
};

void Test(boost::shared_ptr<Simple> simple)
{
	simple->Print();
	std::cout << "In Test(), UseCount: " << simple.use_count() << std::endl;
}

void hello()
{
	// boost::this_thread::sleep(boost::posix_time::seconds(10));
      std::cout <<"Hello world, I'm a thread!"<<std::endl;
	  
}
void hello2()
{
	 boost::this_thread::sleep(boost::posix_time::seconds(10));
      std::cout <<"Hello world, I'm a thread!2"<<std::endl;
	  
}

int main(int argc, char* argv[])
{
	boost::shared_ptr<Simple> mySimple(new Simple(1));
	if (mySimple.get()) //访问裸指针。由于智能指针是一个对象，所以if(smart_object)永远为真。
	{
		mySimple->Print();
		mySimple.get()->m_info = "Hello ";
		mySimple->Print();
		(*mySimple).m_info += "World";
		mySimple->Print();
	}
	std::list<boost::shared_ptr<Simple>> tt;
	tt.push_back(mySimple);
	std::cout << "1. --------------------: " << tt.size() << std::endl;


	std::cout << "1. UseCount: " << mySimple.use_count() << std::endl;
	Test(mySimple);
	std::cout << "2. UseCount: " << mySimple.use_count() << std::endl;
	system("pause");
	return 1;


		boost::threadpool::pool u(10);
		u.schedule(&hello);
		u.schedule(&hello2);
		//u.schedule(&hello);

      //  boost::thread thrd(&hello);
       // thrd.join();
		u.wait();
		std::cout <<"end------------------"<<std::endl;
		system("pause");
        return 0;
}
