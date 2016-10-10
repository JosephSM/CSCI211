#include <iostream>
using namespace std;


// check that no man is married to more than 1 woman
// and visa versa
bool validMarriage(int q[], int c){
	for(int i = 0; i < c; i++){
		if(q[c] == q[i]){ 
			return false;				
		}					
	}
	return true;
}



bool isStable(int q[], int mp[3][3], int wp[3][3]){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){	
			int hubby = i;
			int wife  = q[i];
			int lover = j;
			int loversWife = q[j];


			//if husband likes lover more than wife and....
			if(mp[hubby][lover] < mp[hubby][wife]){       
				int cuckhold;
				for(int k = 0; k < 3; k++){
					if (q[k] == j){
						cuckhold = k;
					}
					//... lover likes husband more than lovers husband
					if(wp[lover][hubby] < wp[lover][cuckhold]){
						return false; // Not Stable
					}
				}
			}


			// if wife likes lover more than her husband and...
			if(wp[wife][lover] < wp[wife][hubby]){
				// lover likes wife more than his own wife
				if(mp[lover][wife] < mp[lover][loversWife]){
					return false; //not stable
				}
			}

		}
	}
	return true;
}

void print(int q[]) {
	static int solution = 0;
		cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
		for (int i = 0; i < 3; ++i)
			cout << i << "\t" << q[i] << "\n";
			cout << "\n";
}


//check all configurations of marriages where all marriages are stable
void checkAllCombinations(int (&q)[3], int (&mp)[3][3], int (&wp)[3][3]){
	int c = 0;
	while(true){
		q[c]++;
		
		if(c == -1) exit(0);
		
		if(c == 3){ 
			if(isStable(q, mp, wp)){
				print(q);
			}
			c--;
		}		
		
		else if(q[c] == 3){
			q[c] = -1;
			c--;
		}
		
		else if(validMarriage(q, c))
			c++; 
	}
}



int main(){				
	static int mp[3][3] = {{0,2,1},  // Man 0 preferences
					               {0,2,1},  // Man 1 preferences
		      	             {1,2,0}}; // Man 2 preferences

									 
	static int wp[3][3] = {{2,1,0},  // Woman 0 preferences
					               {0,1,2},  // Woman 1 preferences
												 {2,0,1}}; // Woman 2 preferences


 	// i is a man
	//q[i] is a woman
	int q[3] = {-1};
	checkAllCombinations(q, mp, wp);
	
	return 0;
}
