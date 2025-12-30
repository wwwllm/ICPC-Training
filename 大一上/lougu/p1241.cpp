#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int b[105]={0};
	int i=0,top=0;
	while(i<s.length()){
		if(s[i]==')'){
			for(int j=i-1;j>=0;j--){
				if (s[j] == '(' && b[j] == 0) {
                    b[i] = b[j] = 1;
                    break;
                }
                else if (s[j] == '[' and b[j] == 0) break;
            
			}
		}
		if(s[i]==']'){
			for(int j=i-1;j>=0;j--){
				if (s[j] == '[' and b[j] == 0) {
                    b[i] = b[j] = 1;
                    break;
                }
                else if (s[j] == '(' and b[j] == 0) break;
            
			}
		}
		i++;
	}
	for (i=0; i<s.length(); i++) {
        if (b[i] == 0) { 
            if (s[i] == '(' || s[i] == ')') cout << "()";
            else cout << "[]";
        }
        else cout << s[i]; 
    }
	return 0;
}
