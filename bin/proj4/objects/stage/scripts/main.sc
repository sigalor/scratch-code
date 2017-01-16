int test(string param1, int param2, real param3)
{
	if(true) { } else { }
	scratch_sayDuration(param1, 1.0);
}

void test2() : scratch_onGreenFlag()
{
	if(true)
	{
		if((bool)1) { }
		else
			if(false) { }
		scratch_sayDuration("Hello", 2.0);
	}
}

void test3() : scratch_onReceive("bye")
{
	scratch_sayDuration("Goodbye", 1.0);
}

void test4() : scratch_onBackdropSwitch("backdrop1")
{
	test2();
	test("hello", 123, 3.14);
}
