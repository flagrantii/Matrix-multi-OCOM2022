#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int MCM(int arr[],int i,int j){
	if(i==j){
		return 0;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	
	int mn=INT_MAX;
	for(int k=i;k<j;k++){
		int tmp=0;
		tmp=MCM(arr,i,k)+MCM(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
		mn=min(mn,tmp);
	}
	return dp[i][j]=mn;
}



main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		memset(dp,-1,sizeof(dp));
		int arr[n+1];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		cout<<MCM(arr,1,n-1)<<"\n";
	}
}
