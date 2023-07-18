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