
//this fucntion will up the lps array required for the KMP algo

void computeLPSArray(char* pat, int M, int* lp)
	{
	    lp[0]=0;
	    int len=0 ,i=1;
	    while(i<M){
	        if(pat[i]==pat[len]){
	            //if characters of suffix and prefix matches
	            //add new character and store the len of current
	            //longest lenth in lp array
	            len++;
	            lp[i] = len;
	            i++;
	        }
	        else{
	            //if they dont match  and the suffix pointer is not on zero 
	            //then move it last of matched suffix end
	            if(len!=0){
	                len = lp[len-1];
	            }
	            else{
	                //else just increment i and store zero in array as
	                //char dont match
	                lp[i]=0;
	                i++;
	            }
	        }
	}
	return;
	        
	    }

int kmpSearch(char*txt ,char*pat){
	int  N = strlen(txt);
	int M = strlen(pat);
	int i=0; //pointer for the txt string
	int j=0; //pointer for pat string
	int lps[M];
	computeLPSArray(txt,M,lps);
	while(i<N){
		if(txt[i]==pat[j]){
			i++;
			j++;
		}
		if(j==M){
			cout<<i-j;
			j = lps[j - 1];
		}
		else if(i<N){
			if(j!=0){
				j = lps[j-1];
			}
			else{
				i++;
			}
		}
	}

}