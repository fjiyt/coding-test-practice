#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector <vector<int>> textQueries(vector<string> sentences, vector <string> queries)
{
    vector <vector<int>> answer(queries.size(), vector<int>());

    unordered_map <string, vector <int>> hash;
    for(int i=0; i<sentences.size(); i++)
    {
        string tmp = sentences[i];
        string ss(tmp);
        string word;

        while(ss >> word)
        {
            hash[word].push_back(i);
        }
    }

    for(int i=0; i<queries.size(); i++)
    {
        vector <int> Unique(sentences.size(),0);
        string tmp = queries[i];
        stringstream ss(tmp);
        string word;
        int count = 0;
        while(ss>>word)
        {
            count++;
            auto item = hash.find(word);

            if(item != hash.end())
            {
                for(int j=0; j<item->second.size(); j++)
                {
                    Unique[item->second[j]]++;
                }
            }
            for(int j=0; j<Unique.size(); j++)
            {
                if(Unique[j]==count)
                {
                    answer[i].push_back(j);
                }
            }
            if(answer[i].size()==0)
            {
                answer.push_back(-1);
            }
        }
    }
    return answer;
}
int main()
{

}