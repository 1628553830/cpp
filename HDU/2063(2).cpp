#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int link[1010][1010];//说明女和男是否配对
int vis[1010];//说明男的是否被挑选
int biao[1010];//说明男的是否被访问
int k,m,n;
bool dfs(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(!biao[i]&&link[x][i]==1)
		{
			biao[i]=1;
			if(!vis[i]||dfs(vis[i])){//男孩i没被挑走或挑男孩i的女孩还能挑选别的男孩
				vis[i]=x;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	while(scanf("%d",&k),k)
	{
		int ans=0;
		memset(link,0,sizeof(link));
		memset(vis,0,sizeof(vis));
		
		scanf("%d%d",&m,&n);
		for(int i=0;i<k;i++)
		{
			int girl,boy;
			scanf("%d%d",&girl,&boy);
			link[girl][boy]=1;
		}
		for(int i=1;i<=m;i++)
		{
			memset(biao,0,sizeof(biao));//一个女孩可以选多个不同的男孩  所以要每换一个女孩进行dfs时都要清0；（即使在上个女孩挑选时男孩被看中了（访问了）这一次还能被访问） 
			if(dfs(i))
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}