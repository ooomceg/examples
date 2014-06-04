
global_state = 1
global_key = "0xff336699"

function startup(a, b)
	print("lua startup successfully!")
end

function lua_add(a, b)
	return a + b
end

function lua_testclass()
	local dc = Derived(5)
	dc:foo(dc:goo())
	print('xoo ret:', dc:xoo(25))
	print('val of str:', dc.str)
end

function lua_testglobal()
	cpp_global_var:xoo(3)
end

function lua_testtbl()
	print()
	for k,v in pairs(mytbl) do
		print(k, v)
	end
	mytbl.property.luck = 10086
end

function lua_printtbl(item)
	if type(item) == "table" then
		for k, v in pairs(item) do
			lua_printtbl(v)
		end
	else
		print(item)
	end
end

function lua_return_tbl()
	local ret = { }
	ret.id = "asfdsdf"
	return ret
end

function lua_test_error()
	print("test_error() called !!")
	lua_test_error_1()
end


function lua_test_error_1()
	print("test_error_1() called !!")
	lua_test_error_2()
end

function lua_test_error_2()
	print("test_error_2() called !!")
	lua_test_error_3()
end

function lua_test_thread()
	test_func_1()
	test_func_2(1.11)
	g_test:test_func_1()
	g_test:test_func_2(2.22)
end