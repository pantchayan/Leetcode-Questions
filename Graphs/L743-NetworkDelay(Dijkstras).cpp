
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    class npair
    {
    public:
        int src = 0;
        int par = 0;
        int w = 0;
        int wsf = 0;

        npair(int src, int par, int w, int wsf)
        {
            this->src = src;
            this->par = par;
            this->w = w;
            this->wsf = wsf;
        }
    };

    struct nComp
    {
    public:
        bool operator()(npair &p1, npair &p2)
        {
            return p1.wsf > p2.wsf; // default min PQ.
            //   return p2.wsf > p1.wsf   // max PQ.
        }
    };

    int networkDelayTime(vector<vector<int>> &times, int N, int K)
    {
        // BFS

        //int src = K;
        priority_queue<npair, vector<npair>, nComp> que;

        que.push(npair(K, -1, 0, 0));

        vector<bool> vis(N + 1, false);

        int maxWsf = 0;

        while (que.size() != 0)
        {
            int size = que.size();
            while (size-- > 0)
            {
                npair vtx = que.top();
                que.pop();
                //cycle check
                if (vis[vtx.src])
                    continue;

                if (vtx.par != -1)
                {
                    maxWsf = max(maxWsf, vtx.wsf);
                }

                vis[vtx.src] = true;

                for (int i = 0; i < times.size(); i++)
                {
                    if (times[i][0] == vtx.src)
                    {
                        int v = times[i][1];

                        if (!vis[v])
                        {
                            int w = times[i][2];
                            que.push(npair(v, vtx.src, w, vtx.wsf + w));
                        }
                    }
                }
            }
        }

        for (int i = 1; i < vis.size(); i++)
        {
            if (vis[i] == false)
            {
                return -1;
            }
        }

        return maxWsf;
    }
};