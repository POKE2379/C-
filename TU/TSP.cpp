#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1000000
 // 无穷大值

int n; // 城市数量
vector<vector<int>> graph; // 城市之间的距离矩阵
vector<int> path; // 当前路径
vector<bool> visited; // 记录城市是否访问过
int bestCost = INF; // 当前最优路径的长度

// 回溯法求解TSP
void TSP(int curCity, int cost, int count) {
  if (count == n && graph[curCity][0] != INF) { // 所有城市都已访问且返回起点
    bestCost = min(bestCost, cost + graph[curCity][0]);//更新最优路径长度
    return;
  }
  
  for (int nextCity = 0; nextCity < n; nextCity++) {
    if (!visited[nextCity] && graph[curCity][nextCity] != INF) {
      visited[nextCity] = true;
      path.push_back(nextCity);
      TSP(nextCity, cost + graph[curCity][nextCity], count + 1);
      path.pop_back();
      visited[nextCity] = false;
    }
  }
}

int main() {
 // 读入城市数量和距离矩阵
//   cout<<"请输入城市数量：";
//   cin >> n;
//     cout<<"请输入城市之间的距离矩阵：";
//   graph.resize(n, vector<int>(n));
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < n; j++) {
//       cin >> graph[i][j];
//     }
//   }
 n = 4;

//城市之间的距离矩阵
graph.resize(n, vector<int>(n));
graph = {
    {INF, 10, 15, 20},
    {10, INF, 35, 25},
    {15, 35, INF, 30},
    {20, 25, 30, INF}
};
  // 初始化路径和访问数组
  path.push_back(0); // 起点为0
  visited.resize(n, false);
  visited[0] = true;
  
  // 开始回溯
  TSP(0, 0, 1);
  
  // 输出最短路径长度
  cout << "最短路径长度: " << bestCost << endl;
  for(int i=0;i<n;i++)
    cout<<"路径为: "<<path[i]<<" ";
  return 0;
}
