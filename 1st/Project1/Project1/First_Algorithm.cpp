// 작성자 : 20402 권성빈
#include <iostream>

using namespace std;

int temp = 0;
int temp1 = 2;
int temp2 = 2;
int result = 0;

int main()
{

	char identity[14]{ 1, };
	cout << "주민등록번호 13자리를 '-' 없이 입력해주십시오." << endl;
	cin >> identity;

	for (int i = 0; i < 12; i++)
	{
		if (i >= 10)
		{
			temp += (identity[i] - '0') * temp2;
			temp2++;
			cout << temp << endl;
		}
		if (i < 10)
		{
			temp += (identity[i] - '0') * temp1;
			temp1++;
			cout << temp << endl;
		}
	}

	result = (11 - (temp % 11));
	cout << result << endl;
	if (result == 11)
	{
		result = 1;
	}
	if (result == 10)
	{
		result = 0;
	}

	if ((identity[12] - '0') != temp)
	{
		cout << "13번째 자리 : " << (identity[12] - '0') << endl;
		cout << "검증값 : " << result << endl;
		cout << "잘못된 주민등록번호입니다!" << endl;
		cout << "프로그램을 종료합니다..." << endl;
		return (0);
	}


	if (identity[6] == '1' || identity[6] == '3')
		cout << "성별 : 남자 " << endl;
	if (identity[6] == '2' || identity[6] == '4')
		cout << "성별 : 여자 " << endl;
	 
	int area = (identity[7] - 48) * 10 + (identity[8] - '0');

	if (area < 9)
	{
		cout << "출생 지역 : 서울 ";
	}
	else if (area < 13)
	{
		cout << "출생 지역 : 부산 ";
	}
	else if (area < 16)
	{
		cout << "출생 지역 : 인천 ";
	}
	else if (area < 19)
	{
		cout << "출생 지역 : 경기도 ";
	}
	else if (area < 26)
	{
		cout << "출생 지역 : 경기도 ";
	}
	else if (area < 35)
	{
		cout << "출생 지역 : 강원도 ";
	}
	else if (area < 40)
	{
		cout << "출생 지역 : 충청북도 ";
	}
	else if (area < 48)
	{
		cout << "출생 지역 : 충청남도 ";
	}
	else if (area < 55)
	{
		cout << "출생 지역 : 전라북도 ";
	}
	else if (area < 67)
	{
		cout << "출생 지역 : 전라남도 ";
	}
	else if (area < 91)
	{
		cout << "출생 지역 : 경상도 ";
	}

	int year = (identity[0] - 48) * 10 + (identity[1] - '0');
	year += identity[6] <= '2' ? 1900 : 2000;
	cout << "출생 연도 : " << year << " ";
	cout << "나이 : " << 2021 - year + 1 << " " << endl;

	return(0);
}