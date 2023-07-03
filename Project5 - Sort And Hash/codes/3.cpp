#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Graph
{
    long long int V;
    vector<long long int>* adj;
    vector<long long int>* vals;
    void fillOrder(long long int v, bool vsted[], vector<long long int>& ST);
    void DFS(long long int v, bool vsted[], vector<long long int>& result);
public:
    long long int findTarget(long long int target);
    void makeEdges(const Graph& g, long long int target);
    long long int findSum(const vector<long long int>& vertics) const;
    Graph(long long int V);
    void addEdge(long long int v, long long int w, long long int weight);
    vector<vector<long long int>> SCCS();
    Graph getTranspose();
    long long findMax(long long int target, long long val);
    void ccc();
    vector<vector<long long int>> results;
};

Graph::Graph(long long int V)
{
    this->V = V;
    adj = new vector<long long int>[V];
    vals = new vector<long long int>[V];
}
long long int Graph::findSum(const vector<long long int>& vertics) const
{
    long long int sum = 0;
    for (int i = 0; i < vertics.size(); i++)
        for (int j = 0; j < adj[vertics[i]].size(); j++)
        {
            if (find(vertics.begin(), vertics.end(), adj[vertics[i]][j]) != vertics.end())
            {
                sum += vals[vertics[i]][j] * (vals[vertics[i]][j] + 1) / 2;
            }
        }
    return sum;
}
void Graph::DFS(long long int v, bool vsted[], vector<long long int>& result)
{
    vsted[v] = true;
    result.push_back(v);

    vector<long long int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!vsted[*i])
            DFS(*i, vsted, result);
}

Graph Graph::getTranspose()
{
    Graph g(V);
    for (long long int v = 0; v < V; v++)
    {
        vector<long long int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}

void Graph::addEdge(long long int v, long long int w, long long int weight)
{
    adj[v].push_back(w);
    vals[v].push_back(weight);
}

void Graph::fillOrder(long long int v, bool vsted[], vector<long long int>& ST)
{
    vsted[v] = true;

    vector<long long int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!vsted[*i])
            fillOrder(*i, vsted, ST);

    ST.push_back(v);
}

vector<vector<long long int>> Graph::SCCS()
{
    vector<vector<long long int>> results;
    vector<long long int> result;
    vector<long long int> ST;

    bool* vsted = new bool[V];
    for (int i = 0; i < V; i++)
        vsted[i] = false;

    for (int i = 0; i < V; i++)
        if (vsted[i] == false)
            fillOrder(i, vsted, ST);

    Graph gr = getTranspose();

    for (int i = 0; i < V; i++)
        vsted[i] = false;

    while (ST.empty() == false)
    {
        long long int v = ST.back();
        ST.pop_back();
        result.clear();
        if (vsted[v] == false)
        {
            gr.DFS(v, vsted, result);
            results.push_back(result);
        }
    }
    return results;
}
long long int Graph::findTarget(long long int target)
{
    for (int i = 0; i < results.size(); i++)
        for (int j = 0; j < results[i].size(); j++)
            if (results[i][j] == target) return i;
    return -1;
}
void Graph::makeEdges(const Graph& g, long long int target)
{
    vector<long long int> children;
    vector<long long int> values;
    vector<long long int>::iterator it;
    for (int i = 0; i < results[target].size(); i++)
    {
        for (int j = 0; j < g.adj[results[target][i]].size(); j++)
        {
            if (find(results[target].begin(), results[target].end(), g.adj[results[target][i]][j]) == results[target].end())
            {
                long long int newVal = g.vals[results[target][i]][j];
                int index = findTarget(g.adj[results[target][i]][j]);
                values.push_back(newVal);
                children.push_back(index);
            }
        }
    }
    for (int i = 0; i < children.size(); i++)
    {
        addEdge(target, children[i], g.findSum(results[children[i]]) + values[i]);
        makeEdges(g, children[i]);
    }
}
long long Graph::findMax(long long int target, long long val) {
    vector<long long> results;
    for (int i = 0; i < adj[target].size(); i++)
    {
        int temp;
        if (vals[target][i] >= 0) {
            if (adj[target][i] == target) {
                temp = vals[target][i];
                vals[target][i] = -1;
                results.push_back(findMax(adj[target][i], val + (temp * (temp + 1) / 2)));
                vals[target][i] = temp;
                continue;
            }
            vals[target][i]--;
            results.push_back(findMax(adj[target][i], val + vals[target][i]) + 1);
            vals[target][i]++;
        }
    }
    return (results.empty()) ? val : *max_element(results.begin(), results.end());
}
int main()
{
    long long int v, e, first, second, weight, target;
    cin >> v >> e;
    Graph g(v);
    for (int i = 0; i < e; i++)
    {
        cin >> first >> second >> weight;
        g.addEdge(first - 1, second - 1, weight);
    }
    g.results = g.SCCS();
    Graph gr(g.results.size());
    cin >> target;
    target--;
    long long int tagetResult = g.findTarget(target);
    gr.results = g.results;
    gr.makeEdges(g, tagetResult);
    cout << gr.findMax(tagetResult, g.findSum(g.results[tagetResult]));

    return 0;
}
