#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	vector<string> words(3);

	for(int i = 0; i < 3; i++){
		cin >> words[i];
	}

	sort(words.begin(), words.end());

	cout << "output: " << endl;

	for(auto &word : words){
		cout << word << endl;
	}
	return 0;
}
