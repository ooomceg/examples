#include "stdafx.h"

extern "C" 
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
};

#include "lua_tinker.h"

lua_State* L = 0;

namespace LuaTest
{
	int cpp_add(int a, int b)
	{
		return a + b;
	}
	
	void test_func()
	{
		lua_tinker::def(L, "cpp_add", cpp_add);
		int res = lua_tinker::call<int>(L, "lua_add", 512, 512);
		cout << "res of lua_add: " << res << endl;
	}

	void test_luamen()
	{
		int state = lua_tinker::get<int>(L, "global_state");
		cout << "state : " << state << endl;
		const char* key = lua_tinker::get<const char*>(L, "global_key");
		cout << "key : " << key << endl;
	}

	class A { };
	class Base
	{
	public:
		Base(int n)
		{
			//str = "hello world";
			cout << "base ctor :" << n << endl;
		}
		virtual int xoo(int x)
		{
			cout << "in Base::xoo" << endl;
			return x*x;
		}
	//private:
		//char* str;
	};
	class Derived : public Base
	{
	public:
		Derived(int n) : Base(n) { str = "hello"; }
		void foo(A a) { cout << "in foo" << endl; }
		A goo() { return A(); }
		virtual int xoo(int x)
		{
			cout << "in Derived::xoo" << endl;
			return x*x*x;
		}

		char* str;
	};
	void test_class()
	{
		lua_tinker::class_add<Base>(L, "Base");
		lua_tinker::class_def<Base>(L, "xoo", &Base::xoo);
		//lua_tinker::class_mem<Base>(L, "str", &Base::str);

		lua_tinker::class_add<Derived>(L, "Derived");
		lua_tinker::class_def<Derived>(L, "foo", &Derived::foo);
		lua_tinker::class_def<Derived>(L, "goo", &Derived::goo);
		lua_tinker::class_inh<Derived, Base>(L);
		lua_tinker::class_con<Derived>(L, lua_tinker::constructor<Derived, int>);
		lua_tinker::class_mem<Derived>(L, "str", &Derived::str); 

		// lua中的子类对象访问父类的属性只能得到userdata？

		lua_tinker::call<void>(L, "lua_testclass");
	}

	Derived g_dc(111);
	void test_global()
	{
		lua_tinker::set(L, "cpp_global_var", &g_dc);
		cout << lua_tinker::call<int>(L, "lua_testglobal") << endl;
	}

	void test_table()
	{
		lua_tinker::table tbl(L, "mytbl");
		tbl.set("level", 99);
		tbl.set("name", "Riven");
		tbl.set("property", lua_tinker::table(L));
		lua_tinker::table tbl_prop = tbl.get<lua_tinker::table>("property");
		tbl_prop.set("atk", 1024);
		tbl_prop.set("def", 998);
		// get tblval set in lua
		lua_tinker::call<void>(L, "lua_testtbl");
		cout << "luck:" << tbl_prop.get<const char*>("luck") << endl;
		lua_tinker::call<void>(L, "lua_printtbl", tbl);
		lua_tinker::table tbl_lua = lua_tinker::call<lua_tinker::table>(L, "lua_return_tbl");
		cout << tbl_lua.get<const char*>("id") << endl;
	}

	void show_error(const char* error)
	{
		printf("_ALERT -> %s\n", error);
	}

	void test_error()
	{
		cout << "cur stack:" << endl;
		lua_tinker::enum_stack(L);

		lua_pushnumber(L, 1);
		cout << "stack aft push 1:" << endl;
		lua_tinker::enum_stack(L);

		lua_tinker::call<void>(L, "lua_test_error");
		lua_tinker::call<void>(L, "lua_test_error_3");

		lua_tinker::def(L, "_ALERT", show_error);
		lua_tinker::call<void>(L, "_ALERT", "test !!!");	// lua错误回调

		lua_tinker::call<void>(L, "lua_test_error");
	}

	int test_func_1(lua_State* L)
	{
		cout << "test_func_1" << endl;
		return lua_yield(L, 0);
	}
	int test_func_2(lua_State* L, float a)
	{
		cout << "test_func_2 " << a << endl;
		return lua_yield(L, 0);
	}
	class CTest
	{
	public:
		int test_func_1(lua_State* L)
		{
			cout << "CTest::test_func_1" << endl;
			return lua_yield(L, 0);
		}
		int test_func_2(lua_State* L, float a)
		{
			cout << "CTest::test_func_2 " << a << endl;
			return lua_yield(L, 0);
		}
	};
	void test_thread()
	{
		lua_tinker::def(L, "test_func_1", &test_func_1);
		lua_tinker::def(L, "test_func_2", &test_func_2);
		
		lua_tinker::class_add<CTest>(L, "CTest");
		lua_tinker::class_def<CTest>(L, "test_func_1", &CTest::test_func_1);
		lua_tinker::class_def<CTest>(L, "test_func_2", &CTest::test_func_2);

		CTest test;
		lua_tinker::set(L, "g_test", &test);
		
		lua_newthread(L);
		lua_getglobal(L, "lua_test_thread");

		cout << "step 1" << endl;
		lua_resume(L, L, 0);

		cout << "step 2" << endl;
		lua_resume(L, L, 0);

		cout << "step 3" << endl;
		lua_resume(L, L, 0);

		cout << "step 4" << endl;
		lua_resume(L, L, 0);
	}
}

int main()
{
	L = luaL_newstate();

	luaL_openlibs(L);

	lua_tinker::dofile(L, "../ScriptTest/script/main.lua");
	lua_tinker::call<int>(L, "startup");

	LuaTest::test_func();
	LuaTest::test_luamen();
	LuaTest::test_class();
	LuaTest::test_global();
	LuaTest::test_table();
	LuaTest::test_error();
	LuaTest::test_thread();

	lua_close(L);

	return 0;
}