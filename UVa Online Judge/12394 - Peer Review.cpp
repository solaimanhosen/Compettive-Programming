#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("-Ofast")
//#define debug
#ifdef debug
#define d_pf            printf
#else
#define d_pf            //
#endif // debug

#define print(arr, n)   for(int i = 0; i < n; i++) printf("%d ", arr[i]); printf("\n");
#define fli()   freopen("in.txt", "r", stdin);
#define flo()   freopen("out.txt", "w", stdout);

template<typename T> int toInt(T t){ stringstream ss; ss << t; int r; ss >> r; return r; }

int nextInt(){
	string buffer;
	getline(cin, buffer);
	return toInt(buffer);
}

template<class t>inline bool fs(t &x)
{
	int c = getchar();
	int sgn = 1;
	while (~c&&c<'0' || c>'9')
	{
		if (c == '-')
			sgn = -1;
		c = getchar();
	}
	for (x = 0; ~c&&'0' <= c&&c <= '9'; c = getchar())
		x = x * 10 + c - '0';
	x *= sgn;
	return ~c;
}

#define MAX     1005

bool used[MAX];
bool visit[MAX];
int counter[MAX];
string name[MAX];
vector<int> reviewList[MAX];

void init(int n)
{
    for(int i = 0; i<= n;i++){
        reviewList[i].clear();
        counter[i] = 0;
        visit[i] = false;
    }
}

int main()
{
    //fli();
    //flo();

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, paper_id, p_count;
    string str;
    while(true){
        cin >> k >> n;
        cin.ignore();
        if(n == 0 && k == 0){
            break;
        }
        init(n);
        for(int i = 1; i <= n; i++){
            getline(cin, str);
            stringstream ss(str);
            ss >> name[i];
            for(int j = 1; j <= k; j++){
                ss >> paper_id;
                reviewList[i].push_back(paper_id);
            }
        }
        p_count = 0;
        for(int i = 1; i <= n;i++){
            int sz = reviewList[i].size();

            //memset(used, false, sizeof(used));
            fill(used+1, used+n+1, false);
            for(int j = 0; j < sz; j++){
                paper_id = reviewList[i][j];
                counter[paper_id]++;
                if(paper_id == i){
                    if(!visit[paper_id]){
                        p_count++;
                        visit[paper_id] = true;
                    }
                }
                else if(name[i] == name[paper_id]){
                    if(!visit[paper_id]){
                        p_count++;
                        visit[paper_id] = true;
                    }
                }
                else if(used[paper_id]){
                    if(!visit[paper_id]){
                        p_count++;
                        visit[paper_id] = true;
                    }
                }
                used[paper_id] = true;
            }
        }

        for(int i = 1; i <= n;i++){
            if(counter[i] != k && !visit[i]){
                p_count++;
            }
        }

        if (!p_count) {
            printf("NO PROBLEMS FOUND\n");
        } else if (p_count == 1) {
            printf("1 PROBLEM FOUND\n");
        } else {
            printf("%d PROBLEMS FOUND\n", p_count);
        }
    }

	return 0;
}

