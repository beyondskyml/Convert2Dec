/*
* ½øÖÆ×ª»»
* 
*/

#include <iostream>
#include <string>
using namespace std;

class Convert
{
public:
	/* data */

	/* function */
	void contral_bin2dec();
	void contral_oct2dec();
	void contral();
	bool num_legal(string num, int upper, int lower);
	int bin2dec(string binary);
	int oct2dec(string onum);
	int hex2dec(string onum);
	int k2dec(string knum, int k);
	int cal_weight(int pos, int base);
};

#define LineRight cout<<"test " <<testNo <<" success :)" <<endl;
#define LineWrong cout<<"test " <<testNo <<" fail XD" <<endl;
#define LineIllegal cout<<"Illegal! Please try again."<<endl;

class TestConvert
{
public:
	TestConvert();
	~TestConvert();

	/* data */
	static int testNo;
	static void test_cal_weight();
	static void test_cal_weight_should_get(int weight, int pos, int base, int testno);

	/* test k to dec */
	static void test_k2dec();
	static void test_k2dec_should_get(int result, string knum, int k, int testno);

	/* test hex to dec */
	static void test_hex2dec();
	static void test_hex2dec_should_get(int result, string hnum, int testno);

	/* test oct to dec */
	static void test_oct2dec();
	static void test_oct2dec_should_get(int result, string onum, int testno);
	static void test_2_oct2dec_should_get_1(string onum);
	static void test_1_oct2dec_should_get_0(string onum);

	/* test bin to dec */
	static void test_bin2dec();
	static void test_1_bin2dec_should_get_0();
	static void test_2_bin2dec_should_get_1();
	static void test_3_bin2dec_should_get_2();
	static void test_4_bin2dec_should_get_3();
	static void test_5_bin2dec_should_get_n();
};

