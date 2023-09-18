#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> decoding(vector<int> result, string &code, int size) {
	if (size >= 2)
	{

		int i, j, k,n;
		i = j = k = n = 0;
		int m = code.length() - size;
		vector<int> left, right;

		for (i = m; i < code.length(); i++)
		{
			if (code.compare(i,1,"0") == 0)
			{
				left.push_back(result[n]);
				j++;
				n++;
			}
			else
			{
				right.push_back(result[n]);
				k++;
				n++;
			}
		}

		code.erase(code.length() - size, code.length());

		right = decoding(right,code,k);
		left = decoding(left,code,j);

		for (i = 0; i < j; i++)
		{
			result[i] = left[i];
		}
		for (i = 0; i < k; i++)
		{
			result[i+ j] = right[i];
		}
	}
	return result;
}

void sort(vector<string> &Array, int size) {
	int j = 0;
	bool swap = true;
	string temp;
	while (swap)
	{
		swap = false;
		j++;
		for (int i = 0; i < size - j; i++)
		{
			if (Array[i] > Array[i + 1])
			{
				temp = Array[i];
				Array[i] = Array[i + 1];
				Array[i + 1] = temp;
				swap = true;
			}
		}
	}
}

int main() {
	int size = 0;
	cin >> size;

	vector<string> Array_mosi;
	vector<string> Array_non_mosi;
	vector<string> Array_full;
	string word;
	int j = 0, k = 0;
	for (int i = 0; i < size; i++)
	{
		cin >> word;
		if ( (word.find("mosi") != -1) || ( word.find("MOSI") != -1 ) || ( word.find("Mosi") != -1 ) || ( word.find("mOsi") != -1 ) || ( word.find("moSi") != -1 ) || ( word.find("mosI") != -1  ) || ( word.find("MOsi") != -1 ) || ( word.find("mOSi") != -1 ) || ( word.find("moSI") != -1) || ( word.find("MoSi") != -1) || ( word.find("MosI") != -1 ) || ( word.find("mOsI") != -1 ) || ( word.find("MOSi") != -1 ) || ( word.find("mOSI") != -1 ) || ( word.find("MoSI") != -1  ) || ( word.find("MOsI") != -1) )
		{
			Array_mosi.push_back(word);
			j++;
		}
		else
		{
			Array_non_mosi.push_back(word);
			k++;
		}
	}

	sort(Array_mosi, j);
	sort(Array_non_mosi, k);

	for (int i = 0; i < j; i++)
	{
		Array_full.push_back(Array_mosi[i]);
	}
	for (int i = 0; i < k; i++)
	{
		Array_full.push_back(Array_non_mosi[i]);
	}

	cout << endl;
	string binery_code;
	cin >> binery_code;
	cout << endl;



	vector<int> result;
	for (int i = 0; i < size; i++)
	{
		result.push_back(i);
	}
	result = decoding(result, binery_code, size);

	for (int i = 0; i < size; i++)
	{
		cout << Array_full[result[i]] << endl;
	}



	return 0;
}
