#include "convert.h"
using namespace std;

int TestConvert::testNo;

int main(){
	Convert ct;
	ct.contral();
	// TestConvert::test_cal_weight();
	// TestConvert::test_k2dec();
	// TestConvert::test_hex2dec();
	// ct.contral_bin2dec();
	// TestConvert::test_oct2dec();
	system("pause");
	return 0;
}
void Convert::contral(){
	while(true){
		cout<<"option: 1. bin to dec\n"
			<<"        2. oct to dec\n"
			<<"        3. hex to dec\n"
			<<"        k. k   to dec\n"
			<<"        q. exit\n"
			<<">>";
		char op;
		cin >> op;
		if(op == 'q')
			break;
		if (op < '1' || (op > '3' && op != 'k')){
			LineIllegal
			continue;
		}

		while(true){
			cout<<"Please input a number(input back to back): ";
			string num;
			cin >> num;
			if(num == "back")
				break;
			switch(op){
				case '1':
					if(num_legal(num, 0, 1)) cout<<"Result: "<<bin2dec(num)<<endl;
					else LineIllegal
					break;
				case '2':
					if(num_legal(num, 0, 7)) cout<<"Result: "<<oct2dec(num)<<endl;
					else LineIllegal
					break;
				case '3':
					if(num_legal(num, 0, 15)) cout<<"Result: "<<hex2dec(num)<<endl;
					else LineIllegal
					break;
				case 'k':
					cout<<"Please input scale: ";
					int k;
					cin >> k;
					if (k < 2)
						LineIllegal
					else if(num_legal(num, 0, k - 1)) cout<<"Result: "<<k2dec(num, k)<<endl;
					else LineIllegal
					break;
				default: LineIllegal break;
			}
		}
	}
}
bool Convert::num_legal(string num, int lower, int upper){
	for (int i = 0; i < num.length(); ++i){
		// if((num[i] - '0') > upper || (num[i] - '0') < lower)
		// 	return false;
		if (num[i] - '0' < 0){
			return false;
		}
		if (upper < 10){
			if (num[i] - '0' > upper){
				return false;
			}
		}
		else {
			if (num[i] - 'a' > upper - 10){
				return false;
			}
		}
	}
	return true;
}
void Convert::contral_oct2dec(){
	while(true){
		cout<<"Please input a oct number(input q to exit): ";
		string num;
		cin >> num;

		if(num == "q")
			break;
		if(num_legal(num, 0, 7))
			cout<<"Result: "<<oct2dec(num)<<endl;
		else
			LineIllegal
	}
}
void Convert::contral_bin2dec(){
	while(true){
		cout<<"Please input a binary number(input q to exit): ";
		string num;
		cin >> num;

		if(num == "q")
			break;
		if(num_legal(num, 0, 1))
			cout<<"Result: "<<bin2dec(num)<<endl;
		else
			LineIllegal
	}
}

/*==============================================================*/
/* k to dec */
int Convert::k2dec(string knum, int k){
	int result = 0;
	/*int l = knum.length();
	int cur_num = knum[l - 1] - '0';
	if (cur_num > 9){
		cur_num = knum[l - 1] - 'a' + 10;
	}
	result += cur_num;*/

	int cur_num = 0;
	int i = 1;
	int base = k;
	for(int l = knum.length(); l > 0; l --){
		cur_num = knum[l - 1] - '0';
		if (cur_num > 9){
			cur_num = knum[l - 1] - 'a' + 10;
		}
		result += (cur_num) * cal_weight(i, base);
		i ++;
	}
	return result;
}
void TestConvert::test_k2dec(){
	test_k2dec_should_get(0, "0", 16, 1);
	test_k2dec_should_get(2, "2", 16, 2);
	test_k2dec_should_get(10, "a", 16, 3);
	test_k2dec_should_get(15, "f", 16, 4);
	test_k2dec_should_get(16, "10", 16, 5);
	test_k2dec_should_get(32, "20", 16, 6);
	test_k2dec_should_get(16 * 16 + 15, "10f", 16, 7);
}
void TestConvert::test_k2dec_should_get(int result, string knum, int k, int testno){
	testNo = testno;
	Convert ct;
	if(ct.k2dec(knum, k) == result) LineRight
	else LineWrong
}
int Convert::cal_weight(int pos, int base){
	int weight = 1;
	for (int i = 0; i < pos - 1; ++i){
		weight *= base;
	}
	return weight;
}
void TestConvert::test_cal_weight(){
	test_cal_weight_should_get(1, 1, 2, 1);
	test_cal_weight_should_get(2, 2, 2, 2);
	test_cal_weight_should_get(1, 1, 3, 3);
	test_cal_weight_should_get(3, 2, 3, 4);
	test_cal_weight_should_get(9, 3, 3, 5);
	test_cal_weight_should_get(27, 4, 3, 6);
	test_cal_weight_should_get(16, 3, 4, 7);
	test_cal_weight_should_get(64, 3, 8, 8);
	test_cal_weight_should_get(1, 1, 16, 9);
	test_cal_weight_should_get(16, 2, 16, 10);
	test_cal_weight_should_get(16 * 16, 3, 16, 11);
}
void TestConvert::test_cal_weight_should_get(int weight, int pos, int base, int testno){
	testNo = testno;
	Convert ct;
	if(ct.cal_weight(pos, base) == weight) LineRight
	else LineWrong
}
/*==============================================================*/
/* hex to dec */
int Convert::hex2dec(string hnum){
	int result = 0;
	int l = hnum.length();
	int cur_num = hnum[l - 1] - '0';
	if (cur_num > 9){
		cur_num = hnum[l - 1] - 'a' + 10;
	}
	result += cur_num;

	int i = 0;
	int base = 16;
	for(l --; l > 0; l --){
		cur_num = hnum[l - 1] - '0';
		if (cur_num > 9){
			cur_num = hnum[l - 1] - 'a' + 10;
		}
		result += (cur_num) * (base << (i * 4));
		i ++;
	}
	return result;
}
void TestConvert::test_hex2dec(){
	test_hex2dec_should_get(0, "0", 1);
	test_hex2dec_should_get(1, "1", 2);
	test_hex2dec_should_get(16, "10", 3);
	test_hex2dec_should_get(16 + 5, "15", 4);
	test_hex2dec_should_get(16 * 16 * 16 * 2 + 16 * 16 + 1, "2101", 5);
}
void TestConvert::test_hex2dec_should_get(int result, string hnum, int testno){
	testNo = testno;
	Convert ct;
	if(ct.hex2dec(hnum) == result) LineRight
	else LineWrong
}
/*==============================================================*/
/* oct to dec */
int Convert::oct2dec(string onum){
	int result = 0;
	int l = onum.length();
	result += onum[l - 1] - '0';
	
	int i = 0;
	int base = 8;
	for(l --; l > 0; l --){
		result += (onum[l - 1] - '0') * (base << (i * 3));
		i ++;
	}
	return result;
}
void TestConvert::test_oct2dec(){
	test_1_oct2dec_should_get_0("0");
	test_2_oct2dec_should_get_1("1");
	test_oct2dec_should_get(0, "0", 3);
	test_oct2dec_should_get(2, "2", 4);
	test_oct2dec_should_get(8, "10", 5);
	test_oct2dec_should_get(64, "100", 6);
	test_oct2dec_should_get(72, "110", 7);
	test_oct2dec_should_get(512, "1000", 8);
	test_oct2dec_should_get(64 + 16 + 3, "123", 9);
}
void TestConvert::test_oct2dec_should_get(int result, string onum, int testno){
	testNo = testno;
	Convert ct;
	if (ct.oct2dec(onum) == result) LineRight
	else LineWrong
}
void TestConvert::test_2_oct2dec_should_get_1(string onum){
	testNo = 2;
	Convert ct;
	if (ct.oct2dec(onum) == 1) LineRight
	else LineWrong
}
void TestConvert::test_1_oct2dec_should_get_0(string onum){
	testNo = 1;
	Convert ct;
	if (ct.oct2dec(onum) == 0) LineRight
	else LineWrong
}
/*==============================================================*/
/* bin to dec */

int Convert::bin2dec(string binary){
	int result = 0;
	char one = '1';
	int i = 1;
	int base = 2;
	int l = binary.length();
	if (binary[l - i] == one)
		result += base >> 1;
	for (i = 2; i - 1 < l; i ++){
		if (binary[l - i] == one)
			result += base << (i - 2);
	}
	return result;
}
/* test bin to dec */
void TestConvert::test_bin2dec(){
	TestConvert::test_1_bin2dec_should_get_0();
	TestConvert::test_2_bin2dec_should_get_1();
	TestConvert::test_3_bin2dec_should_get_2();
	TestConvert::test_4_bin2dec_should_get_3();
	TestConvert::test_5_bin2dec_should_get_n();
}
void TestConvert::test_5_bin2dec_should_get_n(){
	testNo = 5;
	Convert ct;
	if (ct.bin2dec("0001") == 1) LineRight
	else LineWrong
	if (ct.bin2dec("1010") == 10) LineRight
	else LineWrong
}
void TestConvert::test_4_bin2dec_should_get_3(){
	testNo = 4;
	Convert ct;
	if (ct.bin2dec("11") == 3) LineRight
	else LineWrong
}
void TestConvert::test_3_bin2dec_should_get_2(){
	testNo = 3;
	Convert ct;
	if (ct.bin2dec("10") == 2)	LineRight
	else LineWrong
}
void TestConvert::test_2_bin2dec_should_get_1(){
	testNo = 2;
	Convert ct;
	if (ct.bin2dec("1") == 1) LineRight
	else LineWrong
}
void TestConvert::test_1_bin2dec_should_get_0(){
	testNo = 1;
	Convert ct;
	if ( ct.bin2dec("0") == 0 ) LineRight
	else LineWrong
}