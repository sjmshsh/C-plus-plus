#pragma once
#include <memory>
#include <iostream>

using namespace std;

class A
{
public:
	~A()
	{
		cout << "~A()" << endl;
	}
public:
	int _a1 = 0;
	int _a2 = 0;
};

// 1. RAII
// 2. 像指针一样
// 3. 拷贝问题
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr = nullptr)
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		if (_ptr)
		{
			cout << "Delete: " << _ptr << endl;
			delete _ptr;
		}
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};

namespace lxy
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{}

		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}


		~auto_ptr()
		{
			if (_ptr)
			{
				cout << "Delete: " << _ptr << endl;
				delete _ptr;
			}
		}
		
		auto_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				if (_ptr)
				{
					delete _ptr;
				}
				_ptr = ap._ptr;
				ap._ptr = nullptr;
			}
			return *this;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};



	// 简单粗暴，不让拷贝，只适用于一些不需要拷贝的场景
	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{}

		// 防拷贝 C++1
		unique_ptr(unique_ptr<T>& ap) = delete;
		unique_ptr<T>& operator=(unique_ptr<T>& ap) = delete;

		// 防拷贝 C++98
		// 只声明不实现，声明在私有

		~unique_ptr()
		{
			if (_ptr)
			{
				cout << "Delete: " << _ptr << endl;
				delete _ptr;
			}
		}


		unique_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				if (_ptr)
				{
					delete _ptr;
				}
				_ptr = ap._ptr;
				ap._ptr = nullptr;
			}
			return *this;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};



	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pCount(new int(1))
		{}


		shared_ptr(shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pCount(sp._pCount)
		{
			(*_pCount)++;
		}

		// sp1 = sp5
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			// if (this == &sp)
			// 如果我们管理的是同一个资源的话, 就不进行赋值
			if (_ptr == sp->_ptr)
			{
				return *this;
			}
			// --被赋值对象的计数，如果是最后一个对象，要释放资源
			Release();
			// 共管新资源 ++计数
			_ptr = sp._ptr;
			_pCount = sp._pCount;
			(*_pCount)++;

			return *this;
		}

		void Release()
		{
			if (--(*_pCount) == 0)
			{
				cout << "Delete: " << _ptr << endl;
				delete _ptr;
				delete _pCount;
			}
		}

		~shared_ptr()
		{
			Release();
		}


		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;

		int* _pCount;
	};

}








// 管理权转移，被拷贝对象的悬空问题
void test_auto_ptr()
{
	auto_ptr<A> ap1(new A);
	ap1->_a1++;
	ap1->_a2++;

	auto_ptr<A> ap2(ap1);
	ap1->_a1++;
	ap1->_a2++;

	ap2->_a1++;
	ap2->_a2++;
}

// unique_ptr 简单粗暴  不让拷贝就可以了
void test_unique_ptr()
{
	std::unique_ptr<A> up1(new A);
	up1->_a1++;
	up1->_a2++;
}

void test_shared_ptr()
{
	std::shared_ptr<A> sp1(new A);
	std::shared_ptr<A> sp2(sp1);
	sp1->_a1++;
	sp1->_a2++;

	cout << sp2->_a1 << ":" << sp2->_a2 << endl;

	sp2->_a1++;
	sp2->_a2++;

	cout << sp1->_a1 << ":" << sp1->_a2 << endl;
}

struct Node
{
	int _val;
	std::weak_ptr<Node> _next;
	std::weak_ptr<Node> _prev;

	~Node()
	{
		cout << "~Node()" << endl;
	}
};

// 循环引用 -- weak_ptr不是常规的智能指针，没有RAII，不支持直接管理资源
// weak_ptr主要用shared_ptr构造，用来解决shared_ptr循环引用问题
// _next和_prev是weak_ptr的时候，他不参与资源释放管理，可以访问和修改到资源
// 但是不增加计数
// 前提是你可以识别到有循环引用的问题再进行使用
void test_shared_ptr2()
{
	std::shared_ptr<Node> n1(new Node);
	std::shared_ptr<Node> n2(new Node);

	// 循环引用
	n1->_next = n2;
	n2->_prev = n1;
}
