#include<iostream>
using namespace std;
void ans(char* name, int n, char start, int lng,int times,int dd);
void function(char* buffer, int times, char start, int n, int j, char* next, char realstart, int lng,int dd);

int main()
{
	int dd, lng;//dd�I lng ��
	char start,name[100];//start=�}�l�I�P���I
	
	cin >> dd >> lng >> start;

	int n = 0;
	for (int i = 0; i < lng*2 ; i++)//��J���|
	{
		cin >> name[n];
		n++;
	}
	n--;//n�u�|��9
	for (int i = 0; i < lng*2; i++)//������X���G���@��
	{
		if (name[i]==start)
		{
				ans(name, n, start, lng,i,dd);//����|���Ȧs��buffer�A��N�_�l�I�s��realstart
		}
	}
}

void ans(char* name,int n,char start,int lng,int times,int dd)//�s��
{
	char buffer[100];//�s���|����
	char realstart = start;//realstart��@�}�l��J���_�l�I�A�]��start����ȷ|����
	char next[100];//�s�U�@�ӭn�����I
	int j = 1;
	for (int i = 0; i < 100; i++)
	{
		buffer[i] = name[i];
	}

	next[0] = start;
	function(buffer, times, start, n, j, next, realstart, lng,dd); // ��O�_�����ƪ��I
		
}

void function(char* buffer, int times, char start, int n,int j,char* next ,char realstart,int lng,int dd)//��O�_�����ƪ��I
{
	for (int i = times; i < n; i++)
	{
		if (buffer[i] == start)
		{
			if (i % 2 == 0)//���Ƨ����IEX.01 endl;23 endl;45....
			{
				next[j] = buffer[i + 1];
				buffer[i + 1] = 0;//�������ƪ��I�A�������L�����ƪ����u
				buffer[i] = 0;
			}
			else//��Ƨ䰸���I
			{
				next[j] = buffer[i - 1];
				buffer[i - 1] = 0;
				buffer[i] = 0;
			}
			start = next[j];
			j++;
			if (start == realstart)
			{
				if (j == dd+1)//�{���w�g�����Ө������u�F
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
	for (int i = n; i >= 0; i--)//�קK���|�����Ʀr�A�ϵۧ�@���AEX.DC�U�@�Ӥw�g�S���|�F�N�n�ϵۦ^�h��
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
