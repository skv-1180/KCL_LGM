#include <bits/stdc++.h>
using namespace std;

class Vertex
{
    public:
        vector<int> string_ends;
        vector<int> next;

        int parent;
        char parentChar;

        int link;
        vector<int> go;

        Vertex(int k, int p = -1, char pch = '$')
        {
            string_ends.clear();
            next.resize(k,-1);

            parent = p;
            parentChar = pch;

            link = -1;
            go.resize(k,-1);
        }
};

//* BFS-based construction of aho-corasick is remaining *//
class Trie
{
    public:
        int K;
        vector<Vertex>nodes;

        Trie(int k)
        {
            K=k;
            nodes.push_back(Vertex(K));
        }

        void add(string s, int ind)
        {
            int cur = 0;
            for(auto c : s)
            {
                if(nodes[cur].next[c-'a'] == -1)
                {
                    nodes[cur].next[c-'a'] = nodes.size();
                    nodes.push_back(Vertex(K,cur,c));
                }
                cur = nodes[cur].next[c-'a'];
            }
            nodes[cur].string_ends.push_back(ind);
        }

        void build_automation() //O(mk) => m->sum of length of all string
        {
            for(int i=0;i<nodes.size();i++){
                for(int j=0;j<K;j++){
                    go(i,j+'a');
                }
            }
        }

        int get_link(int v){
            if(nodes[v].link == -1){
                if(v == 0 || nodes[v].parent == 0)
                    nodes[v].link = 0;
                else
                    nodes[v].link = go(get_link(nodes[v].parent),nodes[v].parentChar);
            }
            return nodes[v].link;
        }

        int go(int v, char ch){
            int c = ch - 'a';
            if(nodes[v].go[c] == -1){
                if(nodes[v].next[c] != -1)
                    nodes[v].go[c] = nodes[v].next[c];
                else
                    nodes[v].go[c] = v == 0 ? 0 : go(get_link(v),ch);
            }
            return nodes[v].go[c];
        }

        void run_automation(string s) //O(s.length)
        {   
            int ans = 0;
            int cur = 0;
            cout<<cur<<' ';
            for(auto c:s)
            {
                cur = nodes[cur].go[c-'a'];
                cout<<cur<<' ';
                ans += nodes[cur].string_ends.size();
            }
            cout<<endl;
            cout<<ans<<endl;
            return;
        }

        void print(int x=0, vector<bool> lst={}, string s="")
        {
            for(int i=0; i<((int)lst.size())-1; i++)
            {
                if(lst[i]) cout<<"   ";
                else cout<<"|  ";
            }
            if(!lst.empty()) cout<<"|--";

            cout<<x<<' '<<s<<' '<<nodes[x].link<<' '<<nodes[x].string_ends.size()<<'\n';

            int mx = -1;
            for(int i=0; i<K; i++)
                if(nodes[x].next[i] != -1)
                    mx = i;
            
            lst.push_back(false);
            for(int i=0; i<K; i++)
            {
                if(nodes[x].next[i] != -1)
                {
                    s.push_back('a' + i);
                    if(i == mx) lst.back() = true;

                    print(nodes[x].next[i], lst, s);

                    s.pop_back();
                }
            }
            lst.pop_back();
            return;
        }
};


int main()
{
    Trie t(26);

    int n;cin>>n;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        t.add(s,i);
    }

    t.build_automation();

    t.print();
    string s;cin>>s;
    t.run_automation(s);


    return 0;
}