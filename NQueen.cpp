Skip to content
This repository  
Search
Pull requests
Issues
Gist
 @Yajingleo
 Unwatch 1
  Star 0
  Fork 0 Yajingleo/NQueen
 Code  Issues 0  Pull requests 0  Wiki  Pulse  Graphs  Settings
Branch: master Find file Copy pathNQueen/source1.cpp
b4872bc  on Mar 19, 2015
@Yajingleo Yajingleo create NQueen
1 contributor
RawBlameHistory     65 lines (60 sloc)  1.63 KB
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        this->column= vector<int>(n,0);
        this->diagonal=vector<int>(2*n-1,0);
        this->antidiagonal=vector<int>(2*n-1,0);
        vector<int> answer;
        vector<vector<string>> result;
        seekingat(answer, result, 0,n);
        return result;
    }
    
private:
    vector<int> column;
    vector<int> diagonal;
    vector<int> antidiagonal;
void   seekingat(vector<int> answer, vector<vector<string>> &result, int row, int n){
       if (row==n) {
           vector<string> solution;
           for (int i=0; i<n; i++){
                string s(n,'.');
                s[(answer[i])]='Q';
                solution.push_back(s);
           }
           result.push_back(solution);
           return;
       }
       else for (int k=0;k<n;k++){
           if (column[k]==0 && diagonal[k-row+n-1]==0 && antidiagonal[k+row]==0){
			   vector<int> copy1=column;
			   vector<int> copy2=diagonal;
			   vector<int> copy3=antidiagonal;
			   vector<int> key=answer;
            key.push_back(k);
            column[k]=1;
            diagonal[k-row+n-1]=1;
            antidiagonal[k+row]=1;
            seekingat(key, result, row+1, n);

			column=copy1;
            diagonal=copy2;
            antidiagonal=copy3;
           }
		   
       }
   }
};

/*void main(){
	Solution S;
	const int N=4;
	vector<vector<string>> result=S.solveNQueens(N);
	for (int i=0;i<result.size();i++){
		cout << "Solution" << i<<":"<<endl; 
		for (int k=0;k<N;k++){
			cout<< (result[i])[k]<<endl;
		}
	}
	system ("pause");
}
Status API Training Shop Blog About Pricing
© 2016 GitHub, Inc. Terms Privacy Security Contact Help
