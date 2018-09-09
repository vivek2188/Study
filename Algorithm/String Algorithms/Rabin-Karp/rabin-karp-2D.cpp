#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

class RabinKarp2D{
	long long int q;      // A large number that happens to be prime
	int d = 256;	      // Radix of the alphabet
	vector<string>P;      // Pattern
	int h;		      // Height of the pattern
	int w;		      // Width of the pattern
	long long int patternHash;
	/* Powers of RADIX. Used to find the hash when the pattern
           window is shifted. */
	vector<long long int>factors;

	public:
		RabinKarp2D(vector<string>pattern){
			P = pattern;
			h = pattern.size();
			w = pattern[0].size();
			int factor_size = (h-1) + (w-1) + 1;
			factors.push_back(1);
			long long int last = 1;
			for(int i=1;i<factor_size;i++){
				long long int f = (d * last) % q;
				factors.push_back(f);
				last = f;
			}
			patternHash = hash(pattern);
		}

		/*Computes (from scratch) and returns the hash of the 	
		  upper left height * width block of data. */
		long long int hash(vector<string>data){
			long long int result = 0;
			for(int i=0;i<h;i++){
				long long int rowHash = 0;
				for(int j=0;j<w;j++){
					rowHash = (d * rowHash + int(data[i][j])) % q;
				}
				result = (d * result + rowHash) % q;
			}
			return result;
		}

		/* Returns true if pattern matches the text at position i,j. */
		bool check(vector<string>T,int i,int j){
			int x = i;
			int y = j;
			for(int m=0;m<h;m++){
				for(int n=0;n<w;n++){
					if(T[x][y]!=P[m][n])
						return false;
					y++;
				}
				x++;
				y = j;
			}
			return true;
		}

		/* Returns powers of d, modulo q, up to 
                   (height - 1) * (width - 1). */
		vector<long long int> get_factors(){
			return factors;
		}
		
		/* Returns an array [i, j], where i and j are the 
                   coordinates of a match of pattern in text. */
		void search(vector<string>text){
			long long int rowStartHash = hash(text);
			long long int hash = rowStartHash;
			vector<int>ans;
			for(int i=0;i<=text.size()-h;i++){
				if(hash==patternHash and check(text,i,0)){
						cout << "Pattern occurs at " << i << " "  << 0 << "\n";
						return;
				}
				for(int j=0;j<text[0].size()-w;j++){
					hash = shiftRight(hash,text,i,j);
					if(hash==patternHash and check(text,i,j+1)){
						cout << "Pattern occurs at " << i << " "  << j+1 << "\n";
						return;
					}
				}
				rowStartHash = shiftDown(rowStartHash,text,i);
				hash = rowStartHash;
			}
			cout << "Pattern does not exist";
		}
		
			
};

int main(){
	
	return 0;
}
