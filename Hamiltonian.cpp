#include<iostream>
using namespace std;
void ans(char* name, int n, char start, int lng,int times,int dd);
void function(char* buffer, int times, char start, int n, int j, char* next, char realstart, int lng,int dd);

int main()
{
	int dd, lng;//dd點 lng 邊
	char start,name[100];//start=開始點與終點
	
	cin >> dd >> lng >> start;

	int n = 0;
	for (int i = 0; i < lng*2 ; i++)//輸入路徑
	{
		cin >> name[n];
		n++;
	}
	n--;//n只會到9
	for (int i = 0; i < lng*2; i++)//不讓輸出結果都一樣
	{
		if (name[i]==start)
		{
				ans(name, n, start, lng,i,dd);//把路徑的值存到buffer，跟將起始點存到realstart
		}
	}
}

void ans(char* name,int n,char start,int lng,int times,int dd)//存值
{
	char buffer[100];//存路徑的值
	char realstart = start;//realstart放一開始輸入的起始點，因為start之後值會改變
	char next[100];//存下一個要走的點
	int j = 1;
	for (int i = 0; i < 100; i++)
	{
		buffer[i] = name[i];
	}

	next[0] = start;
	function(buffer, times, start, n, j, next, realstart, lng,dd); // 找是否有重複的點
		
}

void function(char* buffer, int times, char start, int n,int j,char* next ,char realstart,int lng,int dd)//找是否有重複的點
{
	for (int i = times; i < n; i++)
	{
		if (buffer[i] == start)
		{
			if (i % 2 == 0)//偶數找基數點EX.01 endl;23 endl;45....
			{
				next[j] = buffer[i + 1];
				buffer[i + 1] = 0;//紀錄重複的點，不能讓他走重複的路線
				buffer[i] = 0;
			}
			else//基數找偶數點
			{
				next[j] = buffer[i - 1];
				buffer[i - 1] = 0;
				buffer[i] = 0;
			}
			start = next[j];
			j++;
			if (start == realstart)
			{
				if (j == dd+1)//程式已經走完該走的路線了
				{
					for (int i = 0; i < dd+1; i++)
					{
						cout << next[i];
					}
					cout << endl;
				}
				else
				{
					j--;
					start = next[j-1];
					function(buffer, times, start, n, j, next, realstart, lng,dd);
				}
			}
		}
	}
	for (int i = n; i >= 0; i--)//避免有漏掉的數字，反著找一次，EX.DC下一個已經沒路徑了就要反著回去找
	{
		if (buffer[i] == start)
		{
			if (i % 2 == 0)
			{
				next[j] = buffer[i + 1];
				buffer[i + 1] = 0;
				buffer[i] = 0;
			}
			else
			{
				next[j] = buffer[i - 1];
				buffer[i - 1] = 0;
				buffer[i] = 0;
			}
			start = next[j];
			j++;
			if (start == realstart)
			{
				if (j == dd+1)
				{
					for (int i = 0; i < dd+1; i++)
					{
						cout << next[i];
					}
					cout << endl;
				}
				else
				{
					j--;
					start = next[j-1];
					function(buffer, times, start, n, j, next, realstart, lng ,dd);
				}
			}
		}
	}
}
