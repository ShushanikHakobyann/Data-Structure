#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <thread>
#include <chrono>
#include <functional>

using namespace std;

struct Edge
{
    string to;
    double cost;
    double duration;
};

class Graph
{
public:
    unordered_map<string, vector<Edge>> adj;

    void addEdge(string src, string dest, double cost, double duration)
    {
        adj[src].push_back({dest, cost, duration});
    }

    void dijkstra(string start, string end, bool byCost)
    {

        if (start == end)
        {
            cout << "\nAlready at destination!\n";
            return;
        }

        if (adj.find(start) == adj.end() || adj.find(end) == adj.end())
        {
            cout << "Airport not found.\n";
            return;
        }

        unordered_map<string, double> dist;
        unordered_map<string, string> parent;

        for (auto &p : adj)
            dist[p.first] = 1e18;

        priority_queue<pair<double, string>,
                       vector<pair<double, string>>,
                       greater<pair<double, string>>>
            pq;

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty())
        {
            auto [d, node] = pq.top();
            pq.pop();

            for (auto &e : adj[node])
            {

                double w = byCost ? e.cost : e.duration;

                if (dist[node] + w < dist[e.to])
                {
                    dist[e.to] = dist[node] + w;
                    parent[e.to] = node;
                    pq.push({dist[e.to], e.to});
                }
            }
        }

        if (dist[end] == 1e18 || parent.find(end) == parent.end())
        {
            cout << "No route found.\n";
            return;
        }

        vector<string> path;
        string cur = end;

        while (cur != start)
        {
            path.push_back(cur);
            cur = parent[cur];
        }
        path.push_back(start);

        reverse(path.begin(), path.end());

        cout << "\n========== ROUTE ==========\n";
        cout << "Path: ";
        for (auto &p : path)
            cout << p << " → ";
        cout << "\n";

        cout << (byCost ? "Total Cost: " : "Total Duration: ")
             << dist[end] << "\n";
        cout << "===========================\n";
    }

    void bfsK(string start, int K)
    {

        if (adj.find(start) == adj.end())
        {
            cout << "Airport not found.\n";
            return;
        }

        queue<pair<string, int>> q;
        set<string> vis;

        q.push({start, 0});
        vis.insert(start);

        cout << "\n=== REACHABLE AIRPORTS ===\n";

        while (!q.empty())
        {
            auto [node, depth] = q.front();
            q.pop();

            if (depth > K)
                continue;

            cout << "- " << node << " (stops: " << depth << ")\n";

            for (auto &e : adj[node])
            {
                if (!vis.count(e.to))
                {
                    vis.insert(e.to);
                    q.push({e.to, depth + 1});
                }
            }
        }

        cout << "==========================\n";
    }

    void articulationPoints()
    {

        unordered_map<string, bool> vis;
        unordered_map<string, int> disc, low;
        unordered_map<string, string> parent;
        set<string> res;

        int timer = 0;

        function<void(string)> dfs = [&](string u)
        {
            vis[u] = true;
            disc[u] = low[u] = ++timer;
            int children = 0;

            for (auto &e : adj[u])
            {
                string v = e.to;

                if (!vis[v])
                {
                    children++;
                    parent[v] = u;
                    dfs(v);

                    low[u] = min(low[u], low[v]);

                    if (parent[u] == "" && children > 1)
                        res.insert(u);

                    if (parent[u] != "" && low[v] >= disc[u])
                        res.insert(u);
                }
                else if (v != parent[u])
                {
                    low[u] = min(low[u], disc[v]);
                }
            }
        };

        for (auto &p : adj)
        {
            if (!vis[p.first])
            {
                parent[p.first] = "";
                dfs(p.first);
            }
        }

        cout << "\n===== CRITICAL AIRPORTS =====\n";
        if (res.empty())
            cout << "None\n";
        for (auto &x : res)
            cout << "* " << x << "\n";
        cout << "=============================\n";
    }
};

void loadCSV(Graph &g, string file)
{
    ifstream f(file);
    string line;

    getline(f, line);

    while (getline(f, line))
    {
        stringstream ss(line);
        string s, d, c, t;

        getline(ss, s, ',');
        getline(ss, d, ',');
        getline(ss, c, ',');
        getline(ss, t, ',');

        g.addEdge(s, d, stod(c), stod(t));
    }
}

void loading()
{
    cout << "Loading network";
    for (int i = 0; i < 3; i++)
    {
        cout << ".";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(400));
    }
    cout << "\nLoaded successfully!\n";
}

int main()
{

    cout << "====================================\n";
    cout << "   FLIGHT CONNECTION OPTIMIZER\n";
    cout << "====================================\n\n";

    loading();

    Graph g;
    loadCSV(g, "flights.csv");

    int ch;

    while (true)
    {

        cout << "\n========= MENU =========\n";
        cout << "1. Cheapest route\n";
        cout << "2. Fastest route\n";
        cout << "3. Reachable airports\n";
        cout << "4. Critical airports\n";
        cout << "5. Exit\n";
        cout << "========================\n";
        cout << "Choice: ";

        cin >> ch;

        if (ch == 5)
            break;

        string s, d;
        int k;

        switch (ch)
        {

        case 1:
            cout << "Source: ";
            cin >> s;
            cout << "Destination: ";
            cin >> d;
            g.dijkstra(s, d, true);
            break;

        case 2:
            cout << "Source: ";
            cin >> s;
            cout << "Destination: ";
            cin >> d;
            g.dijkstra(s, d, false);
            break;

        case 3:
            cout << "Source: ";
            cin >> s;
            cout << "K: ";
            cin >> k;
            g.bfsK(s, k);
            break;

        case 4:
            g.articulationPoints();
            break;
        }
    }

    cout << "\nGoodbye!\n";
}