/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    map<UndirectedGraphNode*, UndirectedGraphNode*> m;
    queue<UndirectedGraphNode*> q;
    q.push(node);
    UndirectedGraphNode *head;
    head = new UndirectedGraphNode(node->label);
    m[node] = head;
    while (!q.empty())
    {
        UndirectedGraphNode *u = q.front();
        q.pop();
        vector<UndirectedGraphNode *> v = u->neighbors;
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            if (m[v[i]] == NULL)
            {
                head = new UndirectedGraphNode(v[i]->label);
                m[v[i]] = head;
                q.push(v[i]);
            }
            m[u]->neighbors.push_back(m[v[i]]);
        }
    }
    return m[node];
}

