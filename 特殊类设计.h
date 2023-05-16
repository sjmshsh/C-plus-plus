#pragma once
#include <mutex>

class HeapOnly
{
public:
	// 2. 提供一个获取对象的接口，并且该接口必须设置为静态成员函数
	static HeapOnly* CreateObj()
	{
		return new HeapOnly;
	}
private:
	// 1. 将构造函数设置为私有
	HeapOnly()
	{}

	// 3. 将拷贝构造函数设置为私有，并且只声明不实现
	HeapOnly(const HeapOnly&);
	// C++11
	// HeapOnly(const HeapOnly&) = delete;
};


//class StackOnly
//{
//public:
//	// 2. 提供一个获取对象的接口，并且该对象必须设置为静态成员函数
//	static StackOnly CreateObj()
//	{
//		return StackOnly();
//	}
//private:
//	// 1. 将构造函数设置为私有
//	StackOnly()
//	{}
//};

class StackOnly
{
public:
	StackOnly()
	{}
private:
	void* operator new(size_t size);
	void operator delete(void* p);
};

void TestStackOnly()
{
	// 在静态区上创建对象
	static StackOnly obj;
}

class CopyBan
{
public:
	CopyBan()
	{}
private:
	CopyBan(const CopyBan&);
	CopyBan& operator=(const CopyBan&);
};

class NonInherit
{
public:
	static NonInherit CreateObj()
	{
		return NonInherit();
	}
private:
	// 将构造函数设置为私有
	NonInherit()
	{}
};

// 单例模式
// 饿汉模式
class SingletonEager
{
public:
	// 3. 提供一个全局访问点获取单例模式
	static SingletonEager* GetInstance()
	{
		return _inst;
	}
private:
	// 1. 将构造函数设置为私有，并防拷贝
	SingletonEager()
	{}

	SingletonEager(const SingletonEager&) = delete;
	SingletonEager& operator=(const SingletonEager&) = delete;

	// 2. 提供一个指向单例对象的static指针
	static SingletonEager* _inst;
};

// 在程序入口之前完成单例对象的初始化
SingletonEager* SingletonEager::_inst = new SingletonEager;



// 懒汉模式
class SingletonLazy
{
public:
	// 3. 提供一个全局访问点获取单例对象
	static SingletonLazy* GetInstance()
	{
		// 双检查
		if (_inst == nullptr)
		{
			_mtx.lock();
			if (_inst == nullptr)
			{
				_inst = new SingletonLazy;
			}
			_mtx.unlock();
		}
		return _inst;
	}

	// 实现一个内嵌垃圾回收类
	class CGarbo
	{
	public:
		~CGarbo()
		{
			if (SingletonLazy::_inst)
			{
				delete SingletonLazy::_inst;
			}
		}
	};

	// 定义一个静态成员变量，程序结束的时候，系统会自动调用它的析构函数从而释放单例对象
	static CGarbo Garbo;

private:
	// 1. 将构造函数设置为私有，并防拷贝
	SingletonLazy()
	{}

	SingletonLazy(const SingletonLazy&) = delete;
	SingletonLazy& operator=(const SingletonLazy&) = delete;

	// 2. 提供一个指针单例对象的static指针
	static SingletonLazy* _inst;
	static std::mutex _mtx; // 互斥锁
};

// 在程序入口之前先将static指针初始化为空
SingletonLazy* SingletonLazy::_inst = nullptr;
SingletonLazy::CGarbo Garbo;
std::mutex SingletonLazy::_mtx; // 初始化互斥锁


class SingletonLazy2
{
public:
	// 2. 提供一个全局访问点获取单例对象
	static SingletonLazy2* GetInstance()
	{
		static SingletonLazy2 inst;
		return &inst;
	}

private:
	// 1. 将构造函数设置为私有，并防止拷贝
	SingletonLazy2()
	{}

	SingletonLazy2(const SingletonLazy2&) = delete;
	SingletonLazy2& operator=(const SingletonLazy2&) = delete;
};
