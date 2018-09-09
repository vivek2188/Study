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
		RabinKarp2D(vector<string>pattern,long long int prime){
			P = pattern;
			h = pattern.size();
			w = pattern[0].size();
			q = prime;
			int factor_size = (h-1) + (w-1) + 1;
			factors.push_back(1);
			long long int last = 1;
			for(int i=1;i<factor_size;i++){
				long long int f = (d * last) % q;
				factors.push_back(f);
				last = f;
			}
			patternHash = hash(pattern);
			cout << "Pattern Hash: " << patternHash << "\n";
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
		
		/* Given the hash of the block at i,j returns the hash at i, j+1. */
		long long int shiftRight(long long int hash,vector<string>text,int i,int j){
			long long int sub = 0;
			int l = i;
			for(int k=factors.size()-1;k>=(w-1);k--)
				sub = (sub + factors[k] * int(text[l++][j])) ;
			long long int add = 0;
			for(int k=0;k<h;k++)
				add = (d * add + int(text[i+k][j+w])) % q;
			hash = (d * (hash - sub) + add) % q;
			if(hash<0)
				hash += q;
			return hash;
		}

		/* Given the hash of the block at i,j return the hash at i+1,j*/
		long long int shiftDown(long long int hash,vector<string> text,int i){
			if(i==text.size()-h)
				return -1;
			long long int add = 0;
			for(int k=0;k<w;k++)
				add = (d * add + int(text[i+h][k])) % q;
			long long int sub = 0;
			for(int k=0;k<w;k++)
				sub = (d * sub + int(text[i][k])) % q;
			int l = 1;
			while(l++<=(h-1))
				sub = (sub * d) % q;
			hash = (d * (hash - sub) + add) % q;
			if(hash<0)
				hash += q;
			return hash;
		}
};

int main(){
	vector<string> text, pattern;
	cout << "Strings in text and pattern: ";
	int n, m;
	cin >> n >> m;
	cout << "Enter text\n";
	while(n--){
		string s;
		cin >> s;
		text.push_back(s);
	}
	cout << "Enter pattern\n";
	while(m--){
		string s;
		cin >> s;
		pattern.push_back(s);
	}
	int prime = pow(10,9)+7;
	//cin >> prime;
	RabinKarp2D obj(pattern,prime);
	obj.search(text);
	return 0;
}
