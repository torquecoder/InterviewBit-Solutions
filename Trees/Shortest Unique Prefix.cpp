struct node
{
    int freq;
    node* alphabet[26];
};

node* getnode()
{
    node* temp;
    temp = (node*)malloc(sizeof(node));
    temp->freq = 0;
    for(int i = 0; i < 26; i++)
        temp->alphabet[i] = NULL;
    return temp;
}

void insert(string s, node* root)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (root->alphabet[s[i]-'a'] == NULL)
        {
            root->alphabet[s[i]-'a'] = getnode();
            root->alphabet[s[i]-'a']->freq++;
            root = root->alphabet[s[i]-'a'];
        }
        else
        {
            root->alphabet[s[i]-'a']->freq++;
            root = root->alphabet[s[i]-'a'];
        }
    }
}

string search(string s, node* root)
{
    string ret = "";
    for (int i = 0; i < s.length(); i++)
    {
        ret += s[i];
        if (root->alphabet[s[i]-'a']->freq == 1)
            return ret;
        else
            root = root->alphabet[s[i]-'a'];
    }
}

vector<string> Solution::prefix(vector<string> &A) {
    int n = A.size();
    node* root = getnode();
    for (int i = 0; i< n; i++)
        insert(A[i], root);
    vector<string> ans;
    for (int i = 0; i < n; i++)
        ans.push_back(search(A[i], root));
    return ans;
}

