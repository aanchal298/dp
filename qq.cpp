#include<bits/stdc++.h>
using namespace std;

struct trie
{
    trie * arr[256];
    bool leaf;
    string value;
    vector<pair<string,string> > v;
    trie()
    {
        for(int i = 0 ; i<26; i++)
            arr[i] = NULL;

          leaf = 0;
   }

};


trie *t = NULL;

string lookup(string key)
{    string meaning;
    if(!t)
        return meaning;
    trie * temp = t;

    for(int i = 0 ; i<key.length(); i++)
    {

        if( temp->arr[key[i]] )
        {
            temp = temp->arr[key[i]];

        }
        else
        {
            break;

        }

        if(i == key.length()-1 && temp->leaf == true)
        {   meaning = temp->value;
            break;
        }

    }
    return meaning;

}


void insertKey(string key, string val)
{   if(!t)
        t = new trie;
    trie * temp = t;
    for(int i = 0 ; i<key.length(); i++)
    {
       if( temp->arr[key[i]] )
        {
            temp = temp->arr[key[i]];

        }
        else
        {
            temp->arr[key[i]] = new trie;
            temp = temp->arr[key[i]];

        }

        if(i == key.length()-1)
        {   temp->value = val;
            temp->leaf = true;
        }


    }

}


int main()
{
    while(1)
    {   int c;
        string s,t;
        cin>>c>>s;
        if(c == 0){
            cin>>t;
            insertKey(s,t);
        }
        else
            cout<<lookup(s)<<endl;

    }
    return 0;
}
